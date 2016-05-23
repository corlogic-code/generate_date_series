#include "postgres.h"
#include "generate_date_series.h"
#include "utils/date.h"
#include "funcapi.h"

#ifdef PG_MODULE_MAGIC
PG_MODULE_MAGIC;
#endif


typedef struct
{
	DateADT		current;
	DateADT		stop;
	int32		step;
} generate_date_series_fctx;


/* generate_date_series()
 * Generate the set of dates from start to stop by step
 */
PG_FUNCTION_INFO_V1(generate_date_series);
Datum
generate_date_series(PG_FUNCTION_ARGS)
{
	FuncCallContext *funcctx;
	generate_date_series_fctx *fctx;
	DateADT	result;

	/* stuff done only on the first call of the function */
	if (SRF_IS_FIRSTCALL())
	{
		DateADT		start = PG_GETARG_DATEADT(0);
		DateADT		stop = PG_GETARG_DATEADT(1);
		int32		step = 1;
		MemoryContext oldcontext;

		/* see if we were given an explicit step size */
		if (PG_NARGS() == 3)
		{
			step = PG_GETARG_INT32(2);
			if (step == 0)
				ereport(ERROR,
						(errcode(ERRCODE_INVALID_PARAMETER_VALUE),
						 errmsg("step size cannot equal zero")));
		}

		/* create a function context for cross-call persistence */
		funcctx = SRF_FIRSTCALL_INIT();

		/*
		 * switch to memory context appropriate for multiple function calls
		 */
		oldcontext = MemoryContextSwitchTo(funcctx->multi_call_memory_ctx);

		/* allocate memory for user context */
		fctx = (generate_date_series_fctx *)
			palloc(sizeof(generate_date_series_fctx));

		/*
		 * Use fctx to keep state from call to call. Seed current with the
		 * original start value
		 */
		fctx->current = start;
		fctx->stop = stop;
		fctx->step = step;

		funcctx->user_fctx = fctx;
		MemoryContextSwitchTo(oldcontext);
	}

	/* stuff done on every call of the function */
	funcctx = SRF_PERCALL_SETUP();

	/*
	 * get the saved state and use current as the result for this iteration
	 */
	fctx = funcctx->user_fctx;
	result = fctx->current;

	if ((fctx->step > 0 && fctx->current <= fctx->stop) ||
		(fctx->step < 0 && fctx->current >= fctx->stop))
	{
		/* increment current in preparation for next iteration */
		fctx->current += fctx->step;

		/* do when there is more left to send */
		SRF_RETURN_NEXT(funcctx, DateADTGetDatum(result));
	}
	/* do when there is no more left */
	SRF_RETURN_DONE(funcctx);
}

