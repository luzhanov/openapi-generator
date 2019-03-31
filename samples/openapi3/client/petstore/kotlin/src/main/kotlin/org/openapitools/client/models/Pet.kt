/**
* OpenAPI Petstore
* This spec is mainly for testing Petstore server and contains fake endpoints, models. Please do not use this for any other purpose. Special characters: \" \\
*
* OpenAPI spec version: 1.0.0
* 
*
* NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
* https://openapi-generator.tech
* Do not edit the class manually.
*/
package org.openapitools.client.models

import org.openapitools.client.models.Category
import org.openapitools.client.models.Tag

import com.squareup.moshi.Json
/**
 * 
 * @param id 
 * @param category 
 * @param name 
 * @param photoUrls 
 * @param tags 
 * @param status pet status in the store
 */
data class Pet (
    val name: kotlin.String,
    val photoUrls: kotlin.Array<kotlin.String>,
    val id: kotlin.Long? = null,
    val category: Category? = null,
    val tags: kotlin.Array<Tag>? = null,
    /* pet status in the store */
    val status: Pet.Status? = null
) {

    /**
    * pet status in the store
    * Values: available,pending,sold
    */
    enum class Status(val value: kotlin.String){
    
        @Json(name = "available") available("available"),
    
        @Json(name = "pending") pending("pending"),
    
        @Json(name = "sold") sold("sold");
    
    }

}

