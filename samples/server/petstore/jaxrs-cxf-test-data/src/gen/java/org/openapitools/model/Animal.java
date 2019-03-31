package org.openapitools.model;

import com.fasterxml.jackson.annotation.JsonSubTypes;
import com.fasterxml.jackson.annotation.JsonTypeInfo;
import javax.validation.constraints.*;
import javax.validation.Valid;

import io.swagger.annotations.ApiModelProperty;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlRootElement;
import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlType;
import javax.xml.bind.annotation.XmlEnum;
import javax.xml.bind.annotation.XmlEnumValue;
import com.fasterxml.jackson.annotation.JsonFormat;
import com.fasterxml.jackson.annotation.JsonProperty;

public class Animal  {
  
  @ApiModelProperty(required = true, value = "")
  private String className;

  @ApiModelProperty(value = "")
  private String color = "red";
 /**
  * Get className
  * @return className
  */
  @JsonProperty("className")
  @NotNull
  public String getClassName() {
    return className;
  }

  /**
   * Sets the <code>className</code> property.
   */
  public void setClassName(String className) {
    this.className = className;
  }

  /**
   * Sets the <code>className</code> property.
   */
  public Animal className(String className) {
    this.className = className;
    return this;
  }

 /**
  * Get color
  * @return color
  */
  @JsonProperty("color")
  public String getColor() {
    return color;
  }

  /**
   * Sets the <code>color</code> property.
   */
  public void setColor(String color) {
    this.color = color;
  }

  /**
   * Sets the <code>color</code> property.
   */
  public Animal color(String color) {
    this.color = color;
    return this;
  }


  @Override
  public String toString() {
    StringBuilder sb = new StringBuilder();
    sb.append("class Animal {\n");
    
    sb.append("    className: ").append(toIndentedString(className)).append("\n");
    sb.append("    color: ").append(toIndentedString(color)).append("\n");
    sb.append("}");
    return sb.toString();
  }

  /**
   * Convert the given object to string with each line indented by 4 spaces
   * (except the first line).
   */
  private static String toIndentedString(java.lang.Object o) {
    if (o == null) {
      return "null";
    }
    return o.toString().replace("\n", "\n    ");
  }
}

