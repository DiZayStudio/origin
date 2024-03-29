--Музыкальные жанры
INSERT INTO genre(name)
values('Рок'),
	  ('Поп-музыка'),
	  ('Классика'),
	  ('Рэп'),
	  ('Джаз'),
	  ('Народная песня');

--Имена исполнителей
INSERT INTO artist (name)
values('Metallica'),
	  ('Земфира'),
	  ('Диана Арбенина'),
	  ('Руки вверх'),
	  ('Егор Крид'),
	  ('Вольфганг Амадей Моцарт'),
	  ('Иоганн Себастьян Бах'),
	  ('Людвиг ван Бетховен'),
	  ('Эминем'),
	  ('Баста'),
	  ('Тимати'),
	  ('Френк Синатра'),
	  ('Луи Армстронг'),
	  ('Надежда Бабкина'),
	  ('Надежда Кадышева'),
	  ('Пелагея'),
	  ('Валерия');

--таблица связи жанра и артистов 
INSERT INTO genreartist(genre_id, artist_id)
values('1','1'),
	  ('1','2'),
	  ('1','3'),
	  ('2','3'),
	  ('4','5'),
	  ('2','4'),
	  ('2','5'),
	  ('3','6'),
	  ('3','7'),
	  ('3','8'),
	  ('4','9'),
	  ('4','10'),
	  ('4','11'),
	  ('5','12'),
	  ('5','13'),
	  ('6','14'),
	  ('6','15'),
	  ('6','16'),
	  ('2','17');
	 

--таблица альбомов 
INSERT INTO album (name, year)
values('72 Seasons',2023),			--Металика
	  ('Земфира',1999),				--Земфира
	  ('Разбуди меня',2018),		--Арбенина
	  ('Маленькие девочки',2001),	--Руки вверх
	  ('Мне нравится',2016),		--Егор Крид
	  ('Recovery',2010),			--Эминем
	  ('Тёплый',2009),				--Баста
	  ('Frankie',2020),				--Френк Сенатра
	  ('Любо, братцы, любо',2003),	--Пелагея
	  ('Мой Сибирский драйв',2009),	--Пелагея
	  ('Голубка белая',2015);		--Кадышева

INSERT INTO albumartist (album_id, artist_id)
values('1','1'),
	  ('2','2'),
	  ('3','3'),
	  ('4','4'),
	  ('5','5'),
	  ('6','9'),
	  ('7','10'),
	  ('8','12'),
	  ('9','16'),
	  ('10','16'),
	  ('11','15'),
	  ('5','17');


INSERT INTO track (name, duration, album_id)
values('Shadows Follow','00:07:39','1'),
	  ('Sleepwalk My Life Away','0:05:28','1'),
	  ('Снег','0:02:39','2'),
	  ('Разбуди меня','0:03:25','3'),
	  ('Так тебе и надо','0:02:42','4'),
	  ('Мне нравится','0:05:29','5'),
	  ('Going Through Changes','0:04:17','6'),
	  ('На аккордеоне','0:03:13','7'),
	  ('I Only Have Eyes for You','0:06:49','8'),
	  ('Доброй нежной ласковой','0:03:39','4'),
	  ('Ай-яй-яй','0:05:19','4'),
	  ('Катастрофически','0:04:32','3'),
	  ('Ты дарила мне розы','0:03:47','3'),
	  ('Не Вечерняя','0:05:28','9'),
	  ('Не Для Тебя','0:03:47','10'),
	  ('Ой, Да Не Вечер','0:02:25','10'),
	  ('Голубка белая','0:03:51','11'),
	  ('Часики','0:04:51','5');
 
INSERT INTO collection (name, release_year)
values('Зарубежная музыка',2019),
	  ('Сборная солянка',2023),
	  ('Кому за 40',2015),
	  ('Весна 2020',2020),
	  ('Лето 2017',2017),
	  ('Отечественные хиты',2016),
	  ('Сборник 1',2000),
	  ('Сборник 2',2005);	 
	 
	 
INSERT INTO collectiontrack (collection_id, track_id)
values('1','1'),
	  ('1','5'),
	  ('1','7'),
	  ('2','1'),
	  ('2','4'),
	  ('2','8'),
	  ('3','10'),
	  ('3','12'),
	  ('4','4'),
	  ('4','7'),
	  ('4','15');
	  
	 