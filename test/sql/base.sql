create extension generate_date_series;
SET datestyle TO iso;
SELECT d.date_val FROM generate_date_series('1991-09-24'::date,'1991-10-01'::date) as d(date_val);
SELECT d.date_val FROM generate_date_series('1991-09-24'::date,'1991-10-02'::date,7) as d(date_val);
SELECT d.date_val FROM generate_date_series('1999-12-31'::date,'1999-12-29'::date,-1) as d(date_val);
