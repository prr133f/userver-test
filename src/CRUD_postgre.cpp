#include "CRUD_postgre.hpp"
#include "models/pg_schema.hpp"
#include "sql/sql_queries.hpp"
#include "userver/components/component_context.hpp"
#include "userver/server/handlers/http_handler_base.hpp"
#include "userver/server/http/http_method.hpp"
#include "userver/storages/postgres/cluster.hpp"
#include "userver/storages/postgres/cluster_types.hpp"
#include "userver/storages/postgres/component.hpp"
#include "userver/storages/postgres/io/row_types.hpp"
#include "userver/storages/postgres/postgres_fwd.hpp"

std::string crud_postgre::Handler::HandleRequestThrow(
    const userver::server::http::HttpRequest& request,
    userver::server::request::RequestContext&) const {
  const auto& method = request.GetMethod();
  switch (method) {
    case userver::server::http::HttpMethod::kGet: {
      auto result = pg_cluster_->Execute(
          userver::storages::postgres::ClusterHostType::kMaster,
          queries::get_query, request.GetArg("name"));
      return Models::ToString(result.AsSingleRow<Models::pg_schema>(
          userver::storages::postgres::kRowTag));
    }
    case userver::server::http::HttpMethod::kPost: {
      auto result = pg_cluster_->Execute(
          userver::storages::postgres::ClusterHostType::kMaster,
          queries::post_query, request.GetArg("name"),
          std::stoi(request.GetArg("count")));
      return std::to_string(result.RowsAffected());
    }
    case userver::server::http::HttpMethod::kPut: {
      auto result = pg_cluster_->Execute(
          userver::storages::postgres::ClusterHostType::kMaster,
          queries::put_query, std::stoi(request.GetArg("new-count")),
          request.GetArg("name"));
      return std::to_string(result.RowsAffected());
    }
    case userver::server::http::HttpMethod::kDelete: {
      auto result = pg_cluster_->Execute(
          userver::storages::postgres::ClusterHostType::kMaster,
          queries::delete_query, request.GetArg("name"));
      return std::to_string(result.RowsAffected());
    }
    default:
      return "";
  }
}
