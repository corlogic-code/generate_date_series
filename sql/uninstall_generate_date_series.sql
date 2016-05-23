set client_min_messages = warning;
begin;
drop function generate_date_series(start_date date, end_date date, step_days integer);
end;

