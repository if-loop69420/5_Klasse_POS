

create table if not exists Alliance (
    id INT PRIMARY KEY,
    name TEXT
);

create table if not exists Airline( 
    id INT PRIMARY KEY,
    name TEXT,
    alliance INT REFERENCES Alliance(id)
);

create table if not exists Airport(
    id INT PRIMARY KEY,
    latitude FLOAT,
    longitude FLOAT,
    name TEXT,
    iata TEXT  
);

create table if not exists Route(
    airline INT REFERENCES Airline(id),
    airport1 INT REFERENCES Airport(id),
    airport2 INT REFERENCES Airport(id)
);