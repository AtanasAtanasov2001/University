function createXMLDocument() {

    let documentImplementation = document.implementation;
    let doc = documentImplementation.createDocument(null, null);
    var pi = doc.createProcessingInstruction("xml",
        "version= \"1.0\"encoding=\"UTF-8\"");
    doc.appendChild(pi);

    let game_library = doc.createElement("game_library");
    doc.appendChild(game_library);

    let game = doc.createElement("game");
    game_library.appendChild(game);

    let id = doc.createElement("id");
    id.setAttribute('code', 'AN');
    game.appendChild(id);

    addHeader(doc, game);
    addDetails(doc, game);
    return doc;
}

function addHeader(doc, game) {
    let game_header = doc.createElement("game_header");
    game.appendChild(game_header);

    let game_name = doc.createElement("game_name");
    game_name.appendChild(doc.createTextNode('game name'));

    let price = doc.createElement("price");
    price.appendChild(doc.createTextNode('Price'));

    let manufacturer = doc.createElement("manufacturer");
    manufacturer.setAttribute('path', '../path');

    let name = doc.createElement("name");
    name.appendChild(doc.createTextNode('name'));

    let location = doc.createElement("location");
    location.appendChild(doc.createTextNode('location'));

    let salary = doc.createElement("salary");
    salary.appendChild(doc.createTextNode('salary'));

    game_header.appendChild(game_name);
    game_header.appendChild(price);
    game_header.appendChild(manufacturer)
    manufacturer.appendChild(name);
    manufacturer.appendChild(location);
    manufacturer.appendChild(salary);

}

function addDetails(doc, game) {
    let game_details = doc.createElement("game_details");
    game.appendChild(game_details);

    let summary = doc.createElement("summary");
    summary.appendChild(doc.createTextNode('Summary text'));

    let publish_date = doc.createElement("publish_date");

    addDate(doc, publish_date);

    let age_restriction = doc.createElement("age_restriction");
    age_restriction.appendChild(doc.createTextNode("Age restriction"));

    let operational_system = doc.createElement("operational_system");
    operational_system.appendChild(doc.createTextNode("Windows/Linux/Mac"));

    let publisher = doc.createElement("publisher");
    publisher.appendChild(doc.createTextNode('publisher'));

    let rating = doc.createElement("rating");
    rating.appendChild(doc.createTextNode("rating"));

    let language = doc.createElement("language");
    language.appendChild(doc.createTextNode("language"));


    game_details.appendChild(summary);
    game_details.appendChild(publish_date);
    game_details.appendChild(age_restriction);
    game_details.appendChild(operational_system);
    game_details.appendChild(rating);
    addGenres(doc, game_details);
    game_details.appendChild(publisher);
    game_details.appendChild(language);

    addAuthors(doc, game_details);

}

function addDate(doc, date, day, month, year) {
    let date_info = doc.createElement("date");
    date_info.setAttribute('day', day);
    date_info.setAttribute('month', month);
    date_info.setAttribute('year', year);
    date.appendChild(date_info);
}

function addGenres(doc, game_details) {
    let genres = doc.createElement("genres");
    let genre = doc.createElement("genre");
    genre.appendChild(doc.createTextNode("genre"));
    genres.appendChild(genre);
    game_details.appendChild(genres);
}

function addAuthors(doc, game_details) {
    let authors = doc.createElement("authors");
    let author = doc.createElement("author");
    authors.appendChild(author);
    game_details.appendChild(authors);

    let author_name = doc.createElement("author_name");
    author_name.appendChild(doc.createTextNode('Author name'));

    let biography = doc.createElement("biography");
    biography.appendChild(doc.createTextNode('biography'));

    let published_games = doc.createElement("published_games");
    published_games.appendChild(doc.createTextNode('published_games'));

    let nationality = doc.createElement("nationality");
    nationality.appendChild(doc.createTextNode('nationality'));

    let birth_day = doc.createElement("birth_day");
    addDate(doc, birth_day);

    author.appendChild(author_name);
    author.appendChild(biography);
    author.appendChild(published_games);
    author.appendChild(nationality);
    author.appendChild(birth_day);

}