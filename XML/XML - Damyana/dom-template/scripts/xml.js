function createXMLDocument() {
    let documentImplementation = document.implementation;
    let doc = documentImplementation.createDocument(null, null);
    var pi = doc.createProcessingInstruction("xml",
        "version= \"1.0\"encoding=\"UTF-8\"");
    doc.appendChild(pi);

    let book_catalog = doc.createElement("book_catalog");
    doc.appendChild(book_catalog);

    let book = doc.createElement("book");
    book_catalog.appendChild(book);

    let id = doc.createElement("id");
    id.setAttribute('code', 'AN');
    book.appendChild(id);

    addHeader(doc, book);
    addDetails(doc, book);
    return doc;
}

function addHeader(doc, book) {
    let book_header = doc.createElement("book_header");
    book.appendChild(book_header);

    let book_name = doc.createElement("book_name");
    book_name.appendChild(doc.createTextNode('Book name'));

    let price = doc.createElement("price");
    price.appendChild(doc.createTextNode('Price'));

    let cover = doc.createElement("cover_path");
    cover.setAttribute('path', '../path');

    book_header.appendChild(book_name);
    book_header.appendChild(price);
    book_header.appendChild(cover);
}

function addDetails(doc, book) {
    let book_details = doc.createElement("book_details");
    book.appendChild(book_details);

    let summary = doc.createElement("summary");
    summary.appendChild(doc.createTextNode('Summary text'));

    let publish_date = doc.createElement("publish_date");

    addDate(doc, publish_date, 2, 10, 1989);

    let pages = doc.createElement("pages");
    pages.appendChild(doc.createTextNode(234));

    let cover_type = doc.createElement("cover_type");
    cover_type.setAttribute('type', 'soft');

    let publisher = doc.createElement("publisher");
    publisher.appendChild(doc.createTextNode('publisher'));

    let rating = doc.createElement("rating");
    rating.appendChild(doc.createTextNode(4.44));


    let language = doc.createElement("language");
    language.setAttribute('name', 'bulgarian');

    book_details.appendChild(summary);
    book_details.appendChild(publish_date);
    book_details.appendChild(pages);
    book_details.appendChild(cover_type);
    book_details.appendChild(rating);
    addGenres(doc, book_details);
    book_details.appendChild(publisher);
    book_details.appendChild(language);

    addAuthors(doc, book_details);

}

function addDate(doc, date, day, month, year) {
    let date_info = doc.createElement("date");
    date_info.setAttribute('day', day);
    date_info.setAttribute('month', month);
    date_info.setAttribute('year', year);
    date.appendChild(date_info);
}

function addGenres(doc, book_details) {
    let genres = doc.createElement("genres");
    let genre = doc.createElement("genre");
    genre.setAttribute('name', 'action');
    genres.appendChild(genre);
    book_details.appendChild(genres);
}

function addAuthors(doc, book_details) {
    let authors = doc.createElement("authors");
    let author = doc.createElement("author");
    authors.appendChild(author);
    book_details.appendChild(authors);

    let author_name = doc.createElement("author_name");
    author_name.appendChild(doc.createTextNode('Author name'));

    let biography = doc.createElement("biography");
    biography.appendChild(doc.createTextNode('biography'));

    let publishes_book = doc.createElement("published_books");
    publishes_book.appendChild(doc.createTextNode('published_books'));

    let nationality = doc.createElement("nationality");
    nationality.appendChild(doc.createTextNode('nationality'));

    let birth_day = doc.createElement("birth_day");
    addDate(doc, birth_day, 23, 5, 1987);

    author.appendChild(author_name);
    author.appendChild(biography);
    author.appendChild(publishes_book);
    author.appendChild(nationality);
    author.appendChild(birth_day);

}