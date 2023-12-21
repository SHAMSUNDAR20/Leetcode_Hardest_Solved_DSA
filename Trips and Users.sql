SELECT request_at AS Day, 
ROUND(SUM(status = 'cancelled_by_client' OR status = 'cancelled_by_driver') / COUNT(*), 2) AS `Cancellation Rate`
FROM Trips
WHERE client_id IN (SELECT users_id FROM Users WHERE banned = 'No')
AND driver_id IN (SELECT users_id FROM Users WHERE banned = 'No')
AND request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY request_at;
