# generate_date_series

[![PGXN version](https://badge.fury.io/pg/generate_date_series.svg)](https://badge.fury.io/pg/generate_date_series)

generate_date_series is an extension that provides a generate_series()-like function that takes date inputs and an integer interval (representing days).

## USAGE
For function documentation and examples, see the [generate_date_series.md file](doc/generate_date_series.md).

## INSTALLATION

Requirements: PostgreSQL 9.2 or greater.

In the directory where you downloaded generate_date_series, run

```bash
make && make install
```

Log into PostgreSQL.

Run the following command:

```sql
CREATE EXTENSION generate_date_series;
```

To all any user to execute this new function, run the following grant:

```sql
GRANTE execute on generate_date_series(date,date,integer) to public;
```

## UPGRADE

Run "make && make install" same as above to put the script files and libraries in place. Then run the following in PostgreSQL itself:

```sql
ALTER EXTENSION generate_date_series UPDATE TO '<latest version>';
```
