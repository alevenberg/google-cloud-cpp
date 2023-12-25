struct TracingMessage {
  absl::optional<opentelemetry::context::Context> create_span;
  absl::optional<opentelemetry::context::Context> flow_control;
  absl::optional<opentelemetry::context::Context> flow_control;
  opentelemetry::context::Context subscribe_span;
};