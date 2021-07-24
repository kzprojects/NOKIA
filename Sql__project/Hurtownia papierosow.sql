Create database hurt;
Connect database hurt;

CREATE TABLE Firmy_dostawcze (
    LP           INTEGER NOT NULL,
    Pelna_nazwa    VARCHAR(60),
    Nazwa_Skrocona   VARCHAR(15),
    Miasto       VARCHAR(20),
    Ul           VARCHAR(30),
    Kod_Pocztowy   INTEGER,
    Telefon      INTEGER
);

CREATE TABLE Firmy_odbiorcze (
    LP           INTEGER NOT NULL,
    Pelna_nazwa  VARCHAR(60),
    Nazwa_skrocona VARCHAR(15),
    Miasto       VARCHAR(20),
    Ul           VARCHAR(30),
    Kod_pocztowy INTEGER,
    Telefon      INTEGER
);

CREATE TABLE Papierosy (
    LP           INTEGER NOT NULL,
    Nazwa          VARCHAR(30),
    Cena_zakupu    INTEGER,
    Cena_sprzedazy INTEGER,
    Kod_produktu   INTEGER  
);

CREATE TABLE Pracownicy (
    LP          INTEGER NOT NULL,
    ID          INTEGER NOT NULL,
    Imie        VARCHAR(20),
    Nazwisko    VARCHAR(20),
    Data_ur        DATE,
    Miejsce_zam    VARCHAR(20),
    Ul             VARCHAR(30),
    Kod_pocztowy   INTEGER,
    Pesel       NUMERIC(11),
    Telefon     INTEGER
);

CREATE TABLE Zarobki (
    LP              INTEGER NOT NULL,
    ID              INTEGER NOT NULL,
    Placa           INTEGER,
    Premia          INTEGER
);

/***********************/
/**** Primary Keys ****/
/*********************/

ALTER TABLE Firmy_dostawcze ADD PRIMARY KEY (LP);

INSERT INTO Firmy_dostawcze (LP, Pelna_nazwa, Nazwa_Skrocona, Miasto, Ul, Kod_Pocztowy, Telefon) VALUES (1, 'Firma handlowo-us≥ugowa "Tytan"', 'Tytan','Kielce','Sienkiewicza','28100','3535678');
INSERT INTO Firmy_dostawcze (LP, Pelna_nazwa, Nazwa_Skrocona, Miasto, Ul, Kod_Pocztowy, Telefon) VALUES (2, 'Firma handlowo-us≥ugowa "Mas"', 'Mas','Krakow','Szymborskiej','10100','323456');
INSERT INTO Firmy_dostawcze (LP, Pelna_nazwa, Nazwa_Skrocona, Miasto, Ul, Kod_Pocztowy, Telefon) VALUES (3, 'Firma handlowo-us≥ugowa "Ures"', 'Ures','Torun','Malarskiego','28890','3123455');
INSERT INTO Firmy_dostawcze (LP, Pelna_nazwa, Nazwa_Skrocona, Miasto, Ul, Kod_Pocztowy, Telefon) VALUES (4, 'Firma handlowo-us≥ugowa "Mako"', 'Mako','Gdansk','Tatara','12700','3000865');
INSERT INTO Firmy_dostawcze (LP, Pelna_nazwa, Nazwa_Skrocona, Miasto, Ul, Kod_Pocztowy, Telefon) VALUES (5, 'Firma handlowo-us≥ugowa "Plok"', 'Plok','Miechow','Bytra','45400','3456455');

COMMIT WORK;

ALTER TABLE Firmy_odbiorcze ADD PRIMARY KEY (LP);

INSERT INTO Firmy_odbiorcze (LP, Pelna_nazwa, Nazwa_skrocona, Miasto, Ul, Kod_pocztowy, Telefon) VALUES (1, 'Firma handlowo-us≥ugowa "Noc"', 'NOC','£Ûdü','MuszkieterÛw','12146','3467821');
INSERT INTO Firmy_odbiorcze (LP, Pelna_nazwa, Nazwa_skrocona, Miasto, Ul, Kod_pocztowy, Telefon) VALUES (2, 'Firma handlowo-us≥ugowa "Baton"', 'Baton','Krakow','Koszycka','25100','3542378');
INSERT INTO Firmy_odbiorcze (LP, Pelna_nazwa, Nazwa_skrocona, Miasto, Ul, Kod_pocztowy, Telefon) VALUES (3, 'Firma handlowo-us≥ugowa "Mis"', 'Mis','Kielce','Sienkiewicza','10100','3678923');
INSERT INTO Firmy_odbiorcze (LP, Pelna_nazwa, Nazwa_skrocona, Miasto, Ul, Kod_pocztowy, Telefon) VALUES (4, 'Firma handlowo-us≥ugowa "Bas"', 'Bas','£Ûdü','Poniaskiego','12146','3123456');
INSERT INTO Firmy_odbiorcze (LP, Pelna_nazwa, Nazwa_skrocona, Miasto, Ul, Kod_pocztowy, Telefon) VALUES (5, 'Firma handlowo-us≥ugowa "Tik"', 'Tik','Lublin','Mickiewicza','34500','3546789');

COMMIT WORK;

ALTER TABLE Papierosy ADD PRIMARY KEY (LP);

INSERT INTO Papierosy (LP, Nazwa, Cena_zakupu, Cena_sprzedazy, Kod_produktu) VALUES (1, 'LM', '4','6','1');
INSERT INTO Papierosy (LP, Nazwa, Cena_zakupu, Cena_sprzedazy, Kod_produktu) VALUES (2, 'Grom', '3','6','2');
INSERT INTO Papierosy (LP, Nazwa, Cena_zakupu, Cena_sprzedazy, Kod_produktu) VALUES (3, 'Malboro', '5','8','5');
INSERT INTO Papierosy (LP, Nazwa, Cena_zakupu, Cena_sprzedazy, Kod_produktu) VALUES (4, 'Golden', '4','7','8');
INSERT INTO Papierosy (LP, Nazwa, Cena_zakupu, Cena_sprzedazy, Kod_produktu) VALUES (5, 'Irys', '3','6','3');
INSERT INTO Papierosy (LP, Nazwa, Cena_zakupu, Cena_sprzedazy, Kod_produktu) VALUES (7, 'Davidoff', '5','8','17');

COMMIT WORK;

ALTER TABLE Pracownicy ADD PRIMARY KEY (ID);

INSERT INTO Pracownicy (LP, ID, Imie, Nazwisko, Data_ur, Miejsce_zam, Ul, Kod_pocztowy, Pesel, Telefon) VALUES (1, '1', 'Maciej','Tuch','19561010','Miechow','Bita','28100','10105612345','3564678');
INSERT INTO Pracownicy (LP, ID, Imie, Nazwisko, Data_ur, Miejsce_zam, Ul, Kod_pocztowy, Pesel, Telefon) VALUES (2, '3', 'Tomek','Bas','19601213','Miechow','Stolarska','28100','13076034444','3456766');
INSERT INTO Pracownicy (LP, ID, Imie, Nazwisko, Data_ur, Miejsce_zam, Ul, Kod_pocztowy, Pesel, Telefon) VALUES (3, '5', 'Boguslaw','Matok','19700809','Miechow','Lutego','28100','23017045676','4587542');
INSERT INTO Pracownicy (LP, ID, Imie, Nazwisko, Data_ur, Miejsce_zam, Ul, Kod_pocztowy, Pesel, Telefon) VALUES (4, '8', 'Leszek','Tuch','19561010','Miechow','Maskowa','28100','10105689898','3456998');
INSERT INTO Pracownicy (LP, ID, Imie, Nazwisko, Data_ur, Miejsce_zam, Ul, Kod_pocztowy, Pesel, Telefon) VALUES (5, '54', 'Wojciech','Luty','19760317','Miechow','Sandomierska','28-100','10107623456','3123456');
INSERT INTO Pracownicy (LP, ID, Imie, Nazwisko, Data_ur, Miejsce_zam, Ul, Kod_pocztowy, Pesel, Telefon) VALUES (6, '15', 'Bartek','Lato','19741111','Miechow','Morska','28100','11117467890','3222233');
INSERT INTO Pracownicy (LP, ID, Imie, Nazwisko, Data_ur, Miejsce_zam, Ul, Kod_pocztowy, Pesel, Telefon) VALUES (7, '18', 'Adam','Stach','19801210','Miechow','Rozmusa','28100','12128034534','3244455');
INSERT INTO Pracownicy (LP, ID, Imie, Nazwisko, Data_ur, Miejsce_zam, Ul, Kod_pocztowy, Pesel, Telefon) VALUES (8, '12', 'Damian','Hak','19780924','Miechow','Grochowa','28100','24047834213','3345433');
INSERT INTO Pracownicy (LP, ID, Imie, Nazwisko, Data_ur, Miejsce_zam, Ul, Kod_pocztowy, Pesel, Telefon) VALUES (9, '17', 'Lucjan','Samad','19601021','Miechow','Bahaterow','28100','04106098088','3787877');
INSERT INTO Pracownicy (LP, ID, Imie, Nazwisko, Data_ur, Miejsce_zam, Ul, Kod_pocztowy, Pesel, Telefon) VALUES (10, '121', 'Szymon','Arab','19500310','Miechow','Janowa','28100','11015076767','3434322');

COMMIT WORK;

ALTER TABLE Zarobki ADD PRIMARY KEY (LP);

INSERT INTO Zarobki (LP, ID, Placa, Premia) VALUES (1, '1','1250','150');
INSERT INTO Zarobki (LP, ID, Placa, Premia) VALUES (2, '3','1250','150');
INSERT INTO Zarobki (LP, ID, Placa, Premia) VALUES (3, '5','1500','200');
INSERT INTO Zarobki (LP, ID, Placa, Premia) VALUES (4, '8','1500','200');
INSERT INTO Zarobki (LP, ID, Placa, Premia) VALUES (5, '54','2350','350');
INSERT INTO Zarobki (LP, ID, Placa, Premia) VALUES (6, '15','1000','100');
INSERT INTO Zarobki (LP, ID, Placa, Premia) VALUES (7, '18','1000','100');
INSERT INTO Zarobki (LP, ID, Placa, Premia) VALUES (8, '12','1000','100');
INSERT INTO Zarobki (LP, ID, Placa, Premia) VALUES (9, '17','1550','140');
INSERT INTO Zarobki (LP, ID, Placa, Premia) VALUES (10, '121','3200','500');
COMMIT WORK;