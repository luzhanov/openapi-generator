/**
 * OpenAPI Petstore
 * This is a sample server Petstore server. For this sample, you can use the api key `special-key` to test the authorization filters.
 *
 * OpenAPI spec version: 1.0.0
 * 
 *
 * NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>


#include "OAIApiRouter.h"
#include "OAIPetApiRequest.h"
#include "OAIStoreApiRequest.h"
#include "OAIUserApiRequest.h"


namespace OpenAPI {

OAIApiRouter::OAIApiRouter() {
    createApiHandlers();
}

OAIApiRouter::~OAIApiRouter(){

}

void OAIApiRouter::createApiHandlers() { 
    mOAIPetApiHandler = QSharedPointer<OAIPetApiHandler>::create();
    mOAIStoreApiHandler = QSharedPointer<OAIStoreApiHandler>::create();
    mOAIUserApiHandler = QSharedPointer<OAIUserApiHandler>::create();
}


void OAIApiRouter::setOAIPetApiHandler(QSharedPointer<OAIPetApiHandler> handler){
    mOAIPetApiHandler = handler;
}
void OAIApiRouter::setOAIStoreApiHandler(QSharedPointer<OAIStoreApiHandler> handler){
    mOAIStoreApiHandler = handler;
}
void OAIApiRouter::setOAIUserApiHandler(QSharedPointer<OAIUserApiHandler> handler){
    mOAIUserApiHandler = handler;
}

void OAIApiRouter::setUpRoutes() {
    
    Routes.insert(QString("%1 %2").arg("POST").arg("/v2/pet").toLower(), [this](QHttpEngine::Socket *socket) {
            auto reqObj = new OAIPetApiRequest(socket, mOAIPetApiHandler);
            reqObj->addPetRequest();
    });
    Routes.insert(QString("%1 %2").arg("GET").arg("/v2/pet/findByStatus").toLower(), [this](QHttpEngine::Socket *socket) {
            auto reqObj = new OAIPetApiRequest(socket, mOAIPetApiHandler);
            reqObj->findPetsByStatusRequest();
    });
    Routes.insert(QString("%1 %2").arg("GET").arg("/v2/pet/findByTags").toLower(), [this](QHttpEngine::Socket *socket) {
            auto reqObj = new OAIPetApiRequest(socket, mOAIPetApiHandler);
            reqObj->findPetsByTagsRequest();
    });
    Routes.insert(QString("%1 %2").arg("PUT").arg("/v2/pet").toLower(), [this](QHttpEngine::Socket *socket) {
            auto reqObj = new OAIPetApiRequest(socket, mOAIPetApiHandler);
            reqObj->updatePetRequest();
    });
    Routes.insert(QString("%1 %2").arg("GET").arg("/v2/store/inventory").toLower(), [this](QHttpEngine::Socket *socket) {
            auto reqObj = new OAIStoreApiRequest(socket, mOAIStoreApiHandler);
            reqObj->getInventoryRequest();
    });
    Routes.insert(QString("%1 %2").arg("POST").arg("/v2/store/order").toLower(), [this](QHttpEngine::Socket *socket) {
            auto reqObj = new OAIStoreApiRequest(socket, mOAIStoreApiHandler);
            reqObj->placeOrderRequest();
    });
    Routes.insert(QString("%1 %2").arg("POST").arg("/v2/user").toLower(), [this](QHttpEngine::Socket *socket) {
            auto reqObj = new OAIUserApiRequest(socket, mOAIUserApiHandler);
            reqObj->createUserRequest();
    });
    Routes.insert(QString("%1 %2").arg("POST").arg("/v2/user/createWithArray").toLower(), [this](QHttpEngine::Socket *socket) {
            auto reqObj = new OAIUserApiRequest(socket, mOAIUserApiHandler);
            reqObj->createUsersWithArrayInputRequest();
    });
    Routes.insert(QString("%1 %2").arg("POST").arg("/v2/user/createWithList").toLower(), [this](QHttpEngine::Socket *socket) {
            auto reqObj = new OAIUserApiRequest(socket, mOAIUserApiHandler);
            reqObj->createUsersWithListInputRequest();
    });
    Routes.insert(QString("%1 %2").arg("GET").arg("/v2/user/login").toLower(), [this](QHttpEngine::Socket *socket) {
            auto reqObj = new OAIUserApiRequest(socket, mOAIUserApiHandler);
            reqObj->loginUserRequest();
    });
    Routes.insert(QString("%1 %2").arg("GET").arg("/v2/user/logout").toLower(), [this](QHttpEngine::Socket *socket) {
            auto reqObj = new OAIUserApiRequest(socket, mOAIUserApiHandler);
            reqObj->logoutUserRequest();
    });
}

void OAIApiRouter::processRequest(QHttpEngine::Socket *socket){
    if( handleRequest(socket) ){
        return;
    }
    if( handleRequestAndExtractPathParam(socket) ){
        return;
    }
    socket->setStatusCode(QHttpEngine::Socket::NotFound);
    if(socket->isOpen()){
        socket->writeHeaders();
        socket->close();
    }
}

bool OAIApiRouter::handleRequest(QHttpEngine::Socket *socket){
    auto reqPath = QString("%1 %2").arg(fromQHttpEngineMethod(socket->method())).arg(socket->path()).toLower();
    if ( Routes.contains(reqPath) ) {
        Routes.value(reqPath).operator()(socket);
        return true;
    }
    return false;
}

bool OAIApiRouter::handleRequestAndExtractPathParam(QHttpEngine::Socket *socket){
    auto reqPath = QString("%1 %2").arg(fromQHttpEngineMethod(socket->method())).arg(socket->path()).toLower();
    {
        auto completePath = QString("%1 %2").arg("DELETE").arg("/v2/pet/{petId}").toLower();
        if ( reqPath.startsWith(completePath.leftRef( completePath.indexOf(QString("/{")))) ) {
            QRegularExpressionMatch match = getRequestMatch( completePath, reqPath );
            if ( match.hasMatch() ){
                QString petId = match.captured(QString("petId").toLower());
                auto reqObj = new OAIPetApiRequest(socket, mOAIPetApiHandler);
                reqObj->deletePetRequest(petId);
                return true;
            }
        }
    }
    {
        auto completePath = QString("%1 %2").arg("GET").arg("/v2/pet/{petId}").toLower();
        if ( reqPath.startsWith(completePath.leftRef( completePath.indexOf(QString("/{")))) ) {
            QRegularExpressionMatch match = getRequestMatch( completePath, reqPath );
            if ( match.hasMatch() ){
                QString petId = match.captured(QString("petId").toLower());
                auto reqObj = new OAIPetApiRequest(socket, mOAIPetApiHandler);
                reqObj->getPetByIdRequest(petId);
                return true;
            }
        }
    }
    {
        auto completePath = QString("%1 %2").arg("POST").arg("/v2/pet/{petId}").toLower();
        if ( reqPath.startsWith(completePath.leftRef( completePath.indexOf(QString("/{")))) ) {
            QRegularExpressionMatch match = getRequestMatch( completePath, reqPath );
            if ( match.hasMatch() ){
                QString petId = match.captured(QString("petId").toLower());
                auto reqObj = new OAIPetApiRequest(socket, mOAIPetApiHandler);
                reqObj->updatePetWithFormRequest(petId);
                return true;
            }
        }
    }
    {
        auto completePath = QString("%1 %2").arg("POST").arg("/v2/pet/{petId}/uploadImage").toLower();
        if ( reqPath.startsWith(completePath.leftRef( completePath.indexOf(QString("/{")))) ) {
            QRegularExpressionMatch match = getRequestMatch( completePath, reqPath );
            if ( match.hasMatch() ){
                QString petId = match.captured(QString("petId").toLower());
                auto reqObj = new OAIPetApiRequest(socket, mOAIPetApiHandler);
                reqObj->uploadFileRequest(petId);
                return true;
            }
        }
    }
    {
        auto completePath = QString("%1 %2").arg("DELETE").arg("/v2/store/order/{orderId}").toLower();
        if ( reqPath.startsWith(completePath.leftRef( completePath.indexOf(QString("/{")))) ) {
            QRegularExpressionMatch match = getRequestMatch( completePath, reqPath );
            if ( match.hasMatch() ){
                QString orderId = match.captured(QString("orderId").toLower());
                auto reqObj = new OAIStoreApiRequest(socket, mOAIStoreApiHandler);
                reqObj->deleteOrderRequest(orderId);
                return true;
            }
        }
    }
    {
        auto completePath = QString("%1 %2").arg("GET").arg("/v2/store/order/{orderId}").toLower();
        if ( reqPath.startsWith(completePath.leftRef( completePath.indexOf(QString("/{")))) ) {
            QRegularExpressionMatch match = getRequestMatch( completePath, reqPath );
            if ( match.hasMatch() ){
                QString orderId = match.captured(QString("orderId").toLower());
                auto reqObj = new OAIStoreApiRequest(socket, mOAIStoreApiHandler);
                reqObj->getOrderByIdRequest(orderId);
                return true;
            }
        }
    }
    {
        auto completePath = QString("%1 %2").arg("DELETE").arg("/v2/user/{username}").toLower();
        if ( reqPath.startsWith(completePath.leftRef( completePath.indexOf(QString("/{")))) ) {
            QRegularExpressionMatch match = getRequestMatch( completePath, reqPath );
            if ( match.hasMatch() ){
                QString username = match.captured(QString("username").toLower());
                auto reqObj = new OAIUserApiRequest(socket, mOAIUserApiHandler);
                reqObj->deleteUserRequest(username);
                return true;
            }
        }
    }
    {
        auto completePath = QString("%1 %2").arg("GET").arg("/v2/user/{username}").toLower();
        if ( reqPath.startsWith(completePath.leftRef( completePath.indexOf(QString("/{")))) ) {
            QRegularExpressionMatch match = getRequestMatch( completePath, reqPath );
            if ( match.hasMatch() ){
                QString username = match.captured(QString("username").toLower());
                auto reqObj = new OAIUserApiRequest(socket, mOAIUserApiHandler);
                reqObj->getUserByNameRequest(username);
                return true;
            }
        }
    }
    {
        auto completePath = QString("%1 %2").arg("PUT").arg("/v2/user/{username}").toLower();
        if ( reqPath.startsWith(completePath.leftRef( completePath.indexOf(QString("/{")))) ) {
            QRegularExpressionMatch match = getRequestMatch( completePath, reqPath );
            if ( match.hasMatch() ){
                QString username = match.captured(QString("username").toLower());
                auto reqObj = new OAIUserApiRequest(socket, mOAIUserApiHandler);
                reqObj->updateUserRequest(username);
                return true;
            }
        }
    }
    return false;
}

}
