#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#endif // DEFINITIONS_H


#define CONF_FILE    std::string("./configuration/config.xml")

#define CONFIG_PATH  std::string("main.CONFIGURATIONS")
#define SECTION_PATH std::string("SECTION")
#define XML_ATTR     std::string("<xmlattr>")
#define ID           std::string("id")
#define IP           std::string("IP")
#define PORT         std::string("PORT")
#define INV_NAME     std::string("INVERTER_NAME")
#define PARAMETERS   std::string("PARAMETERS")
#define DOT          std::string(".")


#define CREATE_PATH(X,Y)   \
        (X+DOT+Y)
