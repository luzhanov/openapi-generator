//
// User.swift
//
// Generated by openapi-generator
// https://openapi-generator.tech
//

import Foundation



public struct User: Codable {

    public var _id: Int64?
    public var _idNum: NSNumber? {
        get {
            return _id.map({ return NSNumber(value: $0) })
        }
    }
    public var username: String?
    public var firstName: String?
    public var lastName: String?
    public var email: String?
    public var password: String?
    public var phone: String?
    /** User Status */
    public var userStatus: Int?
    public var userStatusNum: NSNumber? {
        get {
            return userStatus.map({ return NSNumber(value: $0) })
        }
    }

    public init(_id: Int64?, username: String?, firstName: String?, lastName: String?, email: String?, password: String?, phone: String?, userStatus: Int?) {
        self._id = _id
        self.username = username
        self.firstName = firstName
        self.lastName = lastName
        self.email = email
        self.password = password
        self.phone = phone
        self.userStatus = userStatus
    }

    public enum CodingKeys: String, CodingKey { 
        case _id = "id"
        case username
        case firstName
        case lastName
        case email
        case password
        case phone
        case userStatus
    }


}
