/* 
	1. SELECT EVERYTHING AND ORDER BY EID 
*/
SELECT *
FROM CHINA
ORDER BY EID

/* 
	2. SELECT EID, LAST_NAME, FIRST_NAME and TITLE. Then ORDER BY LAST_NAME first, then FIRST_NAME. Both ASCENDINGLY. 
*/
SELECT EID, LAST_NAME, FIRST_NAME, TITLE
FROM CHINA
ORDER BY LAST_NAME ASC, FIRST_NAME ASC


/* 
	3. SELECT EID, LAST_NAME, FIRST_NAME of anyone who had relationship with CPC 
	GROUP BY each individual and ORDER BY EID
*/
SELECT EID, LAST_NAME, FIRST_NAME
FROM CHINA
WHERE INFO_A LIKE '%CPC%' 
   OR INFO_B LIKE '%CPC%' 
   OR INFO_C LIKE '%CPC%' 
   OR INFO_D LIKE '%CPC%' 
   OR INFO_E LIKE '%CPC%' 
   OR INFO_F LIKE '%CPC%' 
   OR INFO_G LIKE '%CPC%' 
   OR INFO_H LIKE '%CPC%' 
   OR INFO_I LIKE '%CPC%'
   OR INFO_J LIKE '%CPC%'
GROUP BY FRIST_NAME, LAST_NAME
ORDER BY EID

/*
	4. SELECT ALL information from a person, who was a student at Peking University
	GROUP BY each individual and ORDER BY EID
*/
SELECT *
FROM CHINA
WHERE (INFO_A LIKE '%Peking University%' 
   OR INFO_B LIKE '%Peking University%' 
   OR INFO_C LIKE '%Peking University%' 
   OR INFO_D LIKE '%Peking University%' 
   OR INFO_E LIKE '%Peking University%' 
   OR INFO_F LIKE '%Peking University%' 
   OR INFO_G LIKE '%Peking University%' 
   OR INFO_H LIKE '%Peking University%' 
   OR INFO_I LIKE '%Peking University%'
   OR INFO_J LIKE '%Peking University%') 
	AND TITLE IN ('student', 'Student', 'STUDENT')
GROUP BY FIRST_NAME, LAST_NAME
ORDER BY EID

/* 
	5. COUNT the number of people who had experience at Shanghai (9560.029*)
	GROUP BY each individual and ORDER BY EID
	Alternative: WHERE INFO_* IN ('%Shanghai%', '%SHANGHAI%')
*/
SELECT COUNT(EID)
FROM CHINA
WHERE (INFO_A_ID LIKE '%9560.029%' 
   OR INFO_B_ID LIKE '%9560.029%' 
   OR INFO_C_ID LIKE '%9560.029%' 
   OR INFO_D_ID LIKE '%9560.029%' 
   OR INFO_E_ID LIKE '%9560.029%' 
   OR INFO_F_ID LIKE '%9560.029%' 
   OR INFO_G_ID LIKE '%9560.029%' 
   OR INFO_H_ID LIKE '%9560.029%' 
   OR INFO_I_ID LIKE '%9560.029%'
   OR INFO_J_ID LIKE '%9560.029%') 
GROUP BY FIRST_NAME, LAST_NAME
ORDER BY EID

/*
	6. SELECT people whose FRIST_NAME is Wei
	Group by each individual and ORDER BY LAST_NAME
*/
SELECT *
FROM CHINA
WHERE FIRST_NAME = 'Wei'
GROUP BY FIRST_NAME, LAST_NAME
ORDER BY LAST_NAME

/*
	7. SELECT people who had experience in Peking University during 1990-1996
*/
SELECT *
FROM CHINA
WHERE (START_YEAR BETWEEN 1990 AND 1996) 
	AND (END_YEAR BETWEEN 1990 AND 1996) 
	AND (INFO_A LIKE '%Peking University%' 
	   OR INFO_B LIKE '%Peking University%' 
	   OR INFO_C LIKE '%Peking University%' 
	   OR INFO_D LIKE '%Peking University%' 
	   OR INFO_E LIKE '%Peking University%' 
	   OR INFO_F LIKE '%Peking University%' 
	   OR INFO_G LIKE '%Peking University%' 
	   OR INFO_H LIKE '%Peking University%' 
	   OR INFO_I LIKE '%Peking University%'
	   OR INFO_J LIKE '%Peking University%')
GROUP BY FIRST_NAME, LAST_NAME
ORDER BY EID

/*
	8. SELECT people who have different FIRST_NAME and LAST_NAME
*/
SELECT DISTINCT LAST_NAME, FIRST_NAME
FROM CHINA