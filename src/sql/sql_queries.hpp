#pragma once

#include "userver/storages/postgres/query.hpp"
namespace queries {
const userver::storages::postgres::Query get_query{
    "SELECT * FROM hello_schema.users WHERE name=$1",
    userver::storages::postgres::Query::Name{"get_query"}};

const userver::storages::postgres::Query post_query{
    "INSERT INTO hello_schema.users(name, count) VALUES($1, $2)",
    userver::storages::postgres::Query::Name{"post_query"}};

const userver::storages::postgres::Query put_query{
    "UPDATE hello_schema.users SET count = $1 WHERE name = $2",
    userver::storages::postgres::Query::Name{"put_query"}};

const userver::storages::postgres::Query delete_query{
    "DELETE FROM hello_schema.users WHERE name = $1",
    userver::storages::postgres::Query::Name{"delete_query"}};
}  // namespace queries