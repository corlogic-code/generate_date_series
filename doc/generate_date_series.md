# generate_date_series

geneate_date_series is an extension containing one function of the same name. It behaves like the generate_series() functions,
but for pure date values. The step_days parameter is an integer, and if omitted defaults to 1.

## Examples
```sql
create extension generate_date_series;
SET datestyle TO iso;
SELECT d.date_val FROM generate_date_series('1991-09-24'::date,'1991-10-01'::date) as d(date_val);
  date_val  
------------
 1991-09-24
 1991-09-25
 1991-09-26
 1991-09-27
 1991-09-28
 1991-09-29
 1991-09-30
 1991-10-01
(8 rows)

SELECT d.date_val FROM generate_date_series('1991-09-24'::date,'1991-10-02'::date,7) as d(date_val);
  date_val  
------------
 1991-09-24
 1991-10-01
(2 rows)

SELECT d.date_val FROM generate_date_series('1999-12-31'::date,'1999-12-29'::date,-1) as d(date_val);
  date_val  
------------
 1999-12-31
 1999-12-30
 1999-12-29
(3 rows)
```

### Support

Submit issues to the [GitHub issue tracker](https://github.com/moat/generate_date_series/issues).

### Author

Corey Huinker, while working at [Moat](http://moat.com)

### Copyright and License

Copyright (c) 2016, Moat Inc.

Permission to use, copy, modify, and distribute this software and its documentation for any purpose, without fee, and without a written agreement is hereby granted, provided that the above copyright notice and this paragraph and the following two paragraphs appear in all copies.

IN NO EVENT SHALL MOAT INC. BE LIABLE TO ANY PARTY FOR DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, INCLUDING LOST PROFITS, ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF Moat, Inc. HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

MOAT INC. SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. THE SOFTWARE PROVIDED HEREUNDER IS ON AN "AS IS" BASIS, AND Moat, Inc. HAS NO OBLIGATIONS TO PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
