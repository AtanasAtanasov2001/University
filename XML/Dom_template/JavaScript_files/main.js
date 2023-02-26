function serializeDocument(doc) {
    let serializer = new XMLSerializer();
    let serializedDocument = serializer.serializeToString(doc);

    return vkbeautify.xml(serializedDocument);
}

function showGeneratedXML(content) {
    let generatedXmlHtmlElement = document.getElementById('generatedXML');
    generatedXmlHtmlElement.innerText = content;
}

function generateXML() {
    console.log("test");
    let doc = createXMLDocument();
    showGeneratedXML(serializeDocument(doc));
};
