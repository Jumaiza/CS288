import sys
import mysql.connector
import xml.dom.minidom as domApi

# def insert(cursor,vendor):
#     query = 'INSERT INTO '+vendor'(SKU,ProductName,ProductDesc,ProductPrice,RemImgUrl,LocImgUrl,ReviewScore) VALUES (%s,%s,%s)'
#     cursor.execute(query, ('0385514239','Origin',2995))

# def update(cursor):
#     query = 'UPDATE book SET price=%s WHERE isbn=%s'
#     cursor.execute(query, (29.95,'0385514239'))
try:
    cnx = mysql.connector.connect(host='localhost', user='root', password='cs288', database='cs288')
    cursor = cnx.cursor()
    cursor.close()
except mysql.connector.Error as err:
    print(err)

if sys.argv[1] == "vivid":

    doc = domApi.parse(sys.argv[2])

    titleElements = doc.getElementsByTagName("title")
    title = titleElements[0].childNodes[0].nodeValue
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
            break

    print("Remote Image URL:",link)

    print("Local Image URL:",("/Images/"+sku+".jpg"))

    reviewScore = 0.0
    print("Review Score:",reviewScore)

if sys.argv[1] == "lmp":

    doc = domApi.parse(sys.argv[2])

    titleElement = doc.getElementsByTagName("title")
    title = titleElement[0].childNodes[0].nodeValue
    sku = title.split(" - ")[1]
    name = title.split(" - ")[0]
    print("\nSKU:",sku)
    print("Name:",name)

    description = ""
    divs = doc.getElementsByTagName("div")
    for div in divs:
        divClass = div.getAttribute("class")
        if divClass == "show_des border_box":
            pTags = div.getElementsByTagName("p")
            for pTag in pTags:
                for node in pTag.childNodes:
                    if node.nodeType == node.TEXT_NODE:
                        description += node.nodeValue
            break
    print("Product Description:",description)


    spanTags = doc.getElementsByTagName("span")
    price = ""
    for spanTag in spanTags:
        spanClass = spanTag.getAttribute("class")
        if spanClass == ".list_price":
            price = spanTag.childNodes[0].nodeValue
            price = price.replace('$','')
            price = price.replace(',','')
            break
    print("Price:",price)

    link = ""
    imgTags = doc.getElementsByTagName("img")
    for imgTag in imgTags:
        if imgTag.getAttribute('id') == "imgDisp":
            link = imgTag.getAttribute('src')

    print("Remote Image URL:",link)

    print("Local Image URL:",("/Images/"+sku+".jpg"))

    reviewScore = 0.0
    print("Review Score:",reviewScore)

