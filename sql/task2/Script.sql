CREATE TABLE IF NOT EXISTS genre (
    id SERIAL PRIMARY KEY,
    name VARCHAR(100) UNIQUE NOT NULL
);

CREATE TABLE IF NOT EXISTS artist (
    id SERIAL PRIMARY KEY,
    name VARCHAR(100) UNIQUE NOT NULL
);

CREATE TABLE IF NOT EXISTS genreartist (
    genre_id integer REFERENCES genre(id),
    artist_id integer REFERENCES artist(id)
);

CREATE TABLE IF NOT EXISTS album (
    id SERIAL PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    year date
);

CREATE TABLE IF NOT EXISTS albumartist (
    album_id integer REFERENCES album(id),
    artist_id integer REFERENCES artist(id)
);

CREATE TABLE IF NOT EXISTS collection (
    id SERIAL PRIMARY KEY,
    name VARCHAR(100),
    year date
);

CREATE TABLE IF NOT EXISTS track (
    id SERIAL PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    duration time,
    album_id integer REFERENCES album(id)
);


CREATE TABLE IF NOT EXISTS collectiontrack (
    collection_id integer REFERENCES album(id),
    track_id integer REFERENCES track(id)
);