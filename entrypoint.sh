#!/bin/bash

echo "Starting the Python HTTP server on port $HTTP_SERVER_PORT..."
python3 -m http.server $HTTP_SERVER_PORT