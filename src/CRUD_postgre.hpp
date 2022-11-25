#pragma once

#include "userver/components/component_context.hpp"
#include "userver/server/handlers/http_handler_base.hpp"
#include "userver/server/http/http_request.hpp"
#include "userver/server/request/request_context.hpp"
#include "userver/storages/postgres/component.hpp"
#include "userver/storages/postgres/postgres_fwd.hpp"

namespace crud_postgre {
class Handler final : public userver::server::handlers::HttpHandlerBase {
 private:
  userver::storages::postgres::ClusterPtr pg_cluster_;

 public:
  static constexpr std::string_view kName = "handler-postgre";

  Handler(const userver::components::ComponentConfig& config,
          const userver::components::ComponentContext& component_context)
      : HttpHandlerBase(config, component_context),
        pg_cluster_(
            component_context
                .FindComponent<userver::components::Postgres>("postgres-db-1")
                .GetCluster()){};

  std::string HandleRequestThrow(
      const userver::server::http::HttpRequest& request,
      userver::server::request::RequestContext& context) const;
};
}  // namespace crud_postgre