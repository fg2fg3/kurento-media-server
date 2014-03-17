/* Autogenerated with Kurento Idl */

#include <memory>

#include "MediaPipeline.hpp"
#include "HubPort.hpp"
#include "Dispatcher.hpp"
#include <JsonSerializer.hpp>

namespace kurento {

std::shared_ptr<MediaObject> Dispatcher::Factory::createObject (const Json::Value &params)
{
  std::shared_ptr<MediaPipeline> mediaPipeline;
  int garbagePeriod = 0;

  if (!params.isMember ("mediaPipeline")) {
    /* param 'mediaPipeline' not present, raise exception */
    JsonRpc::CallException e (JsonRpc::ErrorCode::SERVER_ERROR_INIT,
                              "'mediaPipeline' parameter is requiered");
    throw e;
  } else {
    JsonSerializer s(false);
    s.JsonValue = params;
    s.SerializeNVP(mediaPipeline);
  }

  if (!params.isMember ("garbagePeriod")) {
    /* param 'garbagePeriod' not present, using default */
    garbagePeriod = 120;
  } else {
    JsonSerializer s(false);
    s.JsonValue = params;
    s.SerializeNVP(garbagePeriod);
  }

  return createObject (mediaPipeline, garbagePeriod);
}

Dispatcher::Factory::StaticConstructor Dispatcher::Factory::staticConstructor;

Dispatcher::Factory::StaticConstructor::StaticConstructor()
{
  if (objectRegistrar) {
    std::shared_ptr <Factory> factory (new Dispatcher::Factory());

    objectRegistrar->registerFactory(factory);
  }
}

void
Dispatcher::Invoker::invoke (std::shared_ptr<MediaObject> obj,
    const std::string &methodName, const Json::Value &params,
    Json::Value &response)
{
  if (methodName == "connect" && params.size() == 2) {
    Json::Value aux;
    std::shared_ptr<HubPort> source;
    std::shared_ptr<HubPort> sink;

    if (!params.isMember ("source")) {
      /* param 'source' not present, raise exception */
      JsonRpc::CallException e (JsonRpc::ErrorCode::SERVER_ERROR_INIT,
                                "'source' parameter is requiered");
      throw e;
    } else {
      std::shared_ptr<MediaObject> obj;

      aux = params["source"];

      if (!aux.isString ()) {
        /* param 'source' has invalid type value, raise exception */
        JsonRpc::CallException e (JsonRpc::ErrorCode::SERVER_ERROR_INIT,
                                "'source' parameter should be a string");
        throw e;
      }

      try {
        obj = HubPort::Factory::getObject (aux.asString ());
      } catch (JsonRpc::CallException &ex) {
        JsonRpc::CallException e (JsonRpc::ErrorCode::SERVER_ERROR_INIT,
                                "'source' object not found: "+ ex.getMessage());
        throw e;
      }

      source = std::dynamic_pointer_cast<HubPort> (obj);

      if (!source) {
        JsonRpc::CallException e (JsonRpc::ErrorCode::SERVER_ERROR_INIT,
                                "'source' object has a invalid type");
        throw e;
      }
    }

    if (!params.isMember ("sink")) {
      /* param 'sink' not present, raise exception */
      JsonRpc::CallException e (JsonRpc::ErrorCode::SERVER_ERROR_INIT,
                                "'sink' parameter is requiered");
      throw e;
    } else {
      std::shared_ptr<MediaObject> obj;

      aux = params["sink"];

      if (!aux.isString ()) {
        /* param 'sink' has invalid type value, raise exception */
        JsonRpc::CallException e (JsonRpc::ErrorCode::SERVER_ERROR_INIT,
                                "'sink' parameter should be a string");
        throw e;
      }

      try {
        obj = HubPort::Factory::getObject (aux.asString ());
      } catch (JsonRpc::CallException &ex) {
        JsonRpc::CallException e (JsonRpc::ErrorCode::SERVER_ERROR_INIT,
                                "'sink' object not found: "+ ex.getMessage());
        throw e;
      }

      sink = std::dynamic_pointer_cast<HubPort> (obj);

      if (!sink) {
        JsonRpc::CallException e (JsonRpc::ErrorCode::SERVER_ERROR_INIT,
                                "'sink' object has a invalid type");
        throw e;
      }
    }

    // TODO: Implement method connect
    std::shared_ptr<Dispatcher> finalObj;
    finalObj = std::dynamic_pointer_cast<Dispatcher> (obj);
    if (!finalObj) {
      JsonRpc::CallException e (JsonRpc::ErrorCode::SERVER_ERROR_INIT,
                                "Object not found or has incorrect type");
      throw e;
    }

    finalObj->connect (source, sink);
    return;
  }

  Hub::Invoker::invoke(obj, methodName, params, response);
}

std::string
Dispatcher::connect(const std::string &eventType, std::shared_ptr<EventHandler> handler)
{
  return Hub::connect (eventType, handler);
}

} /* kurento */

void
Serialize(std::shared_ptr<kurento::Dispatcher> &object, JsonSerializer &serializer)
{
  if (!serializer.IsWriter) {
    try {
      std::shared_ptr<kurento::MediaObject> aux;
      aux = kurento::Dispatcher::Factory::getObject (serializer.JsonValue.asString ());
      object = std::dynamic_pointer_cast<kurento::Dispatcher> (aux);
      return;
    } catch (kurento::JsonRpc::CallException &ex) {
      kurento::JsonRpc::CallException e (kurento::JsonRpc::ErrorCode::SERVER_ERROR_INIT,
                              "'Dispatcher' object not found: "+ ex.getMessage());
      throw e;
    }
  }
  std::shared_ptr<kurento::Hub> aux = std::dynamic_pointer_cast<kurento::Hub> (object);

  void Serialize(std::shared_ptr<kurento::Hub> &object, JsonSerializer &serializer);
  Serialize(aux, serializer);
}

void
Serialize(kurento::Dispatcher &object, JsonSerializer &serializer)
{
  void Serialize(kurento::Hub &object, JsonSerializer &serializer);
  try {
    Serialize(dynamic_cast<kurento::Hub &> (object), serializer);
  } catch (std::bad_cast) {
  }
}