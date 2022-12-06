import sys
import mysql.connector
import xml.dom.minidom as domApi
from glob import glob

if sys.argv[1] == "vivid":

    xhtml_files = glob("*.xhtml")

    for filename in xhtml_files:
        doc = domApi.parse(filename)

        titleElement = doc.getElementsByTagName("title")
        title = titleElement[0].childNodes[0].nodeValue
        sku = title.split("  | ")[1]
        name = title.split("  | ")[0]

        print("SKU:",sku)
        print("Name:",name)

        priceElement = doc.getElementsByTagName("p")[1]
        price = ""
        if len(priceElement.childNodes)==1:
            price = priceElement.childNodes[0].nodeValue
            price = price.replace('$','')
        else:
            priceElement = doc.getElementsByTagName("span")[9]
            price = priceElement.childNodes[0].nodeValue
            price = price.replace('Sale:$','')
            price = price.replace(',','')
        
        print("Price:",price)

