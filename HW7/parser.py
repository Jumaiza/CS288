import sys
import mysql.connector
import xml.dom.minidom as domApi

if sys.argv[1] == "vivid":

    doc = domApi.parse(sys.argv[2])

    titleElement = doc.getElementsByTagName("title")
    title = titleElement[0].childNodes[0].nodeValue
    sku = title.split("  | ")[1]
    name = title.split("  | ")[0]
    print("\nSKU:",sku)
    print("Name:",name)

    description = ""
    divs = doc.getElementsByTagName("div")
    for div in divs:
        divId = div.getAttribute("id")
        if divId == "productDescription":
            pTags = div.getElementsByTagName("p")
            for pTag in pTags:
                if len(pTag.childNodes)>1:
                    for node in pTag.childNodes:
                        if node.nodeType == node.TEXT_NODE:
                            description += node.nodeValue
                    break
                else:
                    for node in pTag.childNodes:
                        if node.nodeType == node.TEXT_NODE:
                            description += node.nodeValue
            break

    print("Product Description:",description)


    priceElement = doc.getElementsByTagName("p")[1]
    price = ""
    if len(priceElement.childNodes)==1:
        price = priceElement.childNodes[0].nodeValue
        price = price.replace('$','')
        price = price.replace(',','')
    else:
        priceElement = doc.getElementsByTagName("span")[9]
        price = priceElement.childNodes[0].nodeValue
        price = price.replace('Sale:$','')
        price = price.replace(',','')
    
    print("Price:",price)

    link = ""
    aTags = doc.getElementsByTagName("a")
    for aTag in aTags:
        if aTag.getAttribute('title')[:13] == "Product Image":
            link = aTag.getAttribute('href')

    print("Remote Image URL:",link)

    print("Local Image URL:",("/Images/"+sku+".jpg"))

    reviewScore = 0.0
    print("Review Score:",reviewScore)

if sys.argv[1] == "lmp":

    print("Hello")

    doc = domApi.parse(sys.argv[2])

    titleElement = doc.getElementsByTagName("title")
    title = titleElement[0].childNodes[0].nodeValue
    sku = title.split("  | ")[1]
    name = title.split("  | ")[0]
    print("\nSKU:",sku)
    print("Name:",name)

    description = ""
    divs = doc.getElementsByTagName("div")
    for div in divs:
        divId = div.getAttribute("id")
        if divId == "productDescription":
            pTags = div.getElementsByTagName("p")
            for pTag in pTags:
                if len(pTag.childNodes)>1:
                    for node in pTag.childNodes:
                        if node.nodeType == node.TEXT_NODE:
                            description += node.nodeValue
                    break
                else:
                    for node in pTag.childNodes:
                        if node.nodeType == node.TEXT_NODE:
                            description += node.nodeValue
            break

    print("Product Description:",description)


    priceElement = doc.getElementsByTagName("p")[1]
    price = ""
    if len(priceElement.childNodes)==1:
        price = priceElement.childNodes[0].nodeValue
        price = price.replace('$','')
        price = price.replace(',','')
    else:
        priceElement = doc.getElementsByTagName("span")[9]
        price = priceElement.childNodes[0].nodeValue
        price = price.replace('Sale:$','')
        price = price.replace(',','')
    
    print("Price:",price)

    link = ""
    aTags = doc.getElementsByTagName("a")
    for aTag in aTags:
        if aTag.getAttribute('title')[:13] == "Product Image":
            link = aTag.getAttribute('href')

    print("Remote Image URL:",link)

    print("Local Image URL:",("/Images/"+sku+".jpg"))

    reviewScore = 0.0
    print("Review Score:",reviewScore)

