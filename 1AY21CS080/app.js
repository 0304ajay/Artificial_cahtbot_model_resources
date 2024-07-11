const axios = require('axios');

const token = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJNYXBDbGFpbXMiOnsiZXhwIjoxNzIwNjk2ODkwLCJpYXQiOjE3MjA2OTY1OTAsImlzcyI6IkFmZm9yZG1lZCIsImp0aSI6ImIyNDAwMDIwLTU0OTEtNGZmOS05OWYzLTNkYzI0MWI3MjM1OCIsInN1YiI6ImtvZGlkZWxhay4yMS5iZWNzQGFjaGFyeWEuYWMuaW4ifSwiY29tcGFueU5hbWUiOiJBQ0hBUllBIElOU1RJVFVURSBPRiBURUNITk9MT0dZIiwiY2xpZW50SUQiOiJiMjQwMDAyMC01NDkxLTRmZjktOTlmMy0zZGMyNDFiNzIzNTgiLCJjbGllbnRTZWNyZXQiOiJWaUhHYXNaSklmQ0R6S0FwIiwib3duZXJOYW1lIjoiay5BamF5IEt1bWFyIFJlZGR5Iiwib3duZXJFbWFpbCI6ImtvZGlkZWxhay4yMS5iZWNzQGFjaGFyeWEuYWMuaW4iLCJyb2xsTm8iOiIxQVkyMUNTMDgwIn0.HgGRjkZWseT3BGlh7wpMQHmmTIePCRIp1csepG6Ybk4";

axios.get('http://20.244.56.144/numbers/prime', {
    headers: {
        Authorization: `Bearer ${token}`
    }
})
.then(response => {
    console.log('Response:', response.data);
})
.catch(error => {
    console.error('Error:', error.message);
});
// {
//     "token_type": "Bearer",
//     "access_token": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJNYXBDbGFpbXMiOnsiZXhwIjoxNzIwNjk2MzY2LCJpYXQiOjE3MjA2OTYwNjYsImlzcyI6IkFmZm9yZG1lZCIsImp0aSI6ImIyNDAwMDIwLTU0OTEtNGZmOS05OWYzLTNkYzI0MWI3MjM1OCIsInN1YiI6ImtvZGlkZWxhay4yMS5iZWNzQGFjaGFyeWEuYWMuaW4ifSwiY29tcGFueU5hbWUiOiJBQ0hBUllBIElOU1RJVFVURSBPRiBURUNITk9MT0dZIiwiY2xpZW50SUQiOiJiMjQwMDAyMC01NDkxLTRmZjktOTlmMy0zZGMyNDFiNzIzNTgiLCJjbGllbnRTZWNyZXQiOiJWaUhHYXNaSklmQ0R6S0FwIiwib3duZXJOYW1lIjoiay5BamF5IEt1bWFyIFJlZGR5Iiwib3duZXJFbWFpbCI6ImtvZGlkZWxhay4yMS5iZWNzQGFjaGFyeWEuYWMuaW4iLCJyb2xsTm8iOiIxQVkyMUNTMDgwIn0.zLlDACdYNv2PPjDrGVtZE_zeW6MVO2Z3cJdC4p71U0c",
//     "expires_in": 1720696366
// }