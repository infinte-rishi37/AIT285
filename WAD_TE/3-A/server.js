const http = require('http');
const fs = require('fs');
const path = require('path');

const PORT = process.env.PORT || 3000;
const publicDirectoryPath = path.join(__dirname, '');

const server = http.createServer((req, res) => {
    // Serve index.html by default
    let filePath = path.join(publicDirectoryPath, 'index.html');

    // Check if requested file exists
    fs.access(filePath, fs.constants.F_OK, (err) => {

        // Read the file and serve
        fs.readFile(filePath, (err, data) => {

            // Set appropriate Content-Type
            let contentType = 'text/html';
            // 'text/css' / 'application/javascript';

            res.setHeader('Content-Type', contentType);
            res.end(data);
        });
    });
});

server.listen(PORT, () => {
    console.log(`Server is running on port http://localhost:${PORT}`);
});