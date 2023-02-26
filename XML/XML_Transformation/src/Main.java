import org.w3c.dom.Document;
import org.xml.sax.SAXException;

import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerException;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
import javax.xml.transform.stream.StreamSource;
import java.io.File;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws ParserConfigurationException, IOException, SAXException, TransformerException {
        File xsl = new File("html_4.xsl");
        File input = new File("game.xml");
        File output = new File("html_4_out.html");

        Document document = DocumentBuilderFactory.newInstance()
                .newDocumentBuilder()
                .parse(input);

        Transformer transformer = TransformerFactory.newInstance()
                .newTransformer(new StreamSource(xsl));

        transformer.transform(new DOMSource(document), new StreamResult(output));
    }
}