/* 
	1. SELECT EVERYTHING AND ORDER BY EID 
*/
SELECT *
FROM [CHINAVITAE].[dbo].[CHINA]
ORDER BY EID

/* 
	2. SELECT LAST_NAME, FIRST_NAME and TITLE. Then ORDER BY LAST_NAME first, then FIRST_NAME. Both ASCENDINGLY. 
*/
SELECT LAST_NAME, FIRST_NAME
FROM [CHINAVITAE].[dbo].[CHINA]
GROUP BY FIRST_NAME, LAST_NAME



/* 
	3. COUNT total CPC people
*/
SELECT COUNT(FIRST_NAME) AS TOTAL_CPC
FROM [CHINAVITAE].[dbo].[CHINA]
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



/*
	4. SELECT ALL information from a person, who was a student at Tsinghua University
*/
SELECT * 
FROM [CHINAVITAE].[dbo].[CHINA]
WHERE (INFO_A LIKE '%Tsinghua%' 
   OR INFO_B LIKE '%Tsinghua%' 
   OR INFO_C LIKE '%Tsinghua%' 
   OR INFO_D LIKE '%Tsinghua%' 
   OR INFO_E LIKE '%Tsinghua%' 
   OR INFO_F LIKE '%Tsinghua%' 
   OR INFO_G LIKE '%Tsinghua%' 
   OR INFO_H LIKE '%Tsinghua%' 
   OR INFO_I LIKE '%Tsinghua%'
   OR INFO_J LIKE '%Tsinghua%') 
   AND TITLE IN ('student', 'Student', 'STUDENT')



/* 
	5. People who had experience at Shanghai (9560.029*)
	Alternative: WHERE INFO_* IN ('%Shanghai%', '%SHANGHAI%')
*/
SELECT *
FROM [CHINAVITAE].[dbo].[CHINA]
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

/*
	6. SELECT people whose FRIST_NAME is Wei
	Group by LAST_NAME, FIRST_NAME and ORDER BY LAST_NAME
*/
SELECT LAST_NAME, FIRST_NAME
FROM [CHINAVITAE].[dbo].[CHINA]
WHERE FIRST_NAME = 'Wei'
GROUP BY LAST_NAME, FIRST_NAME
ORDER BY LAST_NAME

/*
	7. SELECT people who had experience in Tsinghua during 1990-1996
   MAKE SURE DATES ARE INTEGER
*/
SELECT *
FROM [CHINAVITAE].[dbo].[CHINA]
WHERE ((START_YEAR BETWEEN '1990' AND '1996') 
   AND (END_YEAR BETWEEN '1990' AND '1996') 
   AND (INFO_A LIKE '%Tsinghua%' 
      OR INFO_B LIKE '%Tsinghua%' 
      OR INFO_C LIKE '%Tsinghua%' 
      OR INFO_D LIKE '%Tsinghua%' 
      OR INFO_E LIKE '%Tsinghua%' 
      OR INFO_F LIKE '%Tsinghua%' 
      OR INFO_G LIKE '%Tsinghua%' 
      OR INFO_H LIKE '%Tsinghua%' 
      OR INFO_I LIKE '%Tsinghua%'
      OR INFO_J LIKE '%Tsinghua%'))




/*
	8. SELECT people who have different FIRST_NAME and LAST_NAME
*/
SELECT DISTINCT LAST_NAME, FIRST_NAME
FROM [CHINAVITAE].[dbo].[CHINA]


