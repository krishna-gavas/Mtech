#!/bin/bash
source config.sh

#-------------------To show all tables in database
# echo "Table Name: "
# mysql -u'root' -p'' TEST_SSL<<EOFMYSQL
# show tables;
# EOFMYSQL

echo "Count of all records"
mysql -u$USERNAME -p'' TEST_SSL<<EOFMYSQL
select count(*) from TEST_SSL;
EOFMYSQL
