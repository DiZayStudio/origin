--Количество исполнителей в каждом жанре;
SELECT name, COUNT(artist_id) FROM genreartist ga
LEFT JOIN genre g ON ga.genre_id = g.id 
GROUP BY name;

--Количество треков, вошедших в альбомы 2019-2020 годов;
SELECT count(track_id) FROM collectiontrack ct
LEFT JOIN collection c ON ct.collection_id = c.id  
WHERE release_year = 2019 OR release_year = 2020;

--Средняя продолжительность треков по каждому альбому;;
SELECT a.name, AVG(duration) FROM track t
LEFT JOIN album a ON t.album_id = a.id 
GROUP BY a.name;

--Все исполнители, которые не выпустили альбомы в 2020 году;
SELECT ar.name FROM artist ar 
JOIN albumartist aa ON ar.id = aa.artist_id
JOIN album a ON aa.album_id = a.id
WHERE NOT a.year = 2020;

--Названия сборников, в которых присутствует конкретный исполнитель (выберите сами)
SELECT c.name FROM collection c
JOIN collectiontrack ct ON c.id = ct.collection_id 
JOIN track t ON ct.track_id = t.id
JOIN album a ON t.album_id = a.id
JOIN albumartist aa ON a.id = aa.album_id
JOIN artist ar ON aa.artist_id = ar.id 
WHERE ar.name LIKE 'Эминем';

--Название альбомов, в которых присутствуют исполнители более 1 жанра;
SELECT a.name, count(*) FROM album a 
JOIN albumartist aa ON a.id = aa.album_id 
JOIN artist ar ON ar.id = aa.artist_id 
JOIN genreartist ga ON ar.id = ga.artist_id 
JOIN genre g ON ga.genre_id = g.id 
GROUP BY a.name
HAVING count(*) > 1;

--название треков, которые не входят в сборники;
SELECT t.name  FROM track t 
LEFT JOIN collectiontrack c ON t.id = c.track_id 
WHERE collection_id IS null;

--Исполнителя(-ей), написавшего самый короткий по продолжительности трек
SELECT a3.name FROM track t
JOIN album a ON t.album_id = a.id 
JOIN albumartist a2 ON a.id = a2.album_id 
JOIN artist a3 ON a2.artist_id = a3.id
WHERE t.duration = (SELECT MIN(t2.duration) FROM track t2);

--Название альбомов, содержащих наименьшее количество треков
SELECT a.name, count(*) FROM album a 
JOIN track t ON a.id = t.album_id 
GROUP BY a.name
HAVING COUNT(*) = 1;
