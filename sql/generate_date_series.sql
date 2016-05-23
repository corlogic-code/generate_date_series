
create function generate_date_series(start_date date, end_date date, step_days integer default 1)
returns setof date
as 'MODULE_PATHNAME','generate_date_series'
language c immutable strict;

comment on function generate_date_series(start_date date, end_date date, step_days integer)
is E'generate_series(), but for date types.';

