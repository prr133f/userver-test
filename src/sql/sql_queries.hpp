#pragma once

#include "userver/storages/postgres/query.hpp"
namespace queries {
const userver::storages::postgres::Query get_query{
    "SELECT * FROM $1", userver::storages::postgres::Query::Name{"get_query"}};

const userver::storages::postgres::Query post_query{
    "INSERT INTO $1(name, count) VALUES($2, $3)",
    userver::storages::postgres::Query::Name{"post_query"}};

const userver::storages::postgres::Query put_query{
    "UPDATE $1 SET count = $2 WHERE name = $3",
    userver::storages::postgres::Query::Name{"put_query"}};

const userver::storages::postgres::Query delete_query{
    "DELETE FROM $1 WHERE name = $2",
    userver::storages::postgres::Query::Name{"delete_query"}};
}  // namespace queries