#!/bin/bash

# Check if the user provided a URL argument
if [ $# -ne 1 ]; then
    echo "Usage: $0 <URL>"
    exit 1
fi

# Send GET request to the provided URL and display the body if status code is 200
curl -s -o /tmp/body -w "%{http_code}" "$1" > /dev/null
status_code=$(cat /tmp/body)
if [ "$status_code" -eq 200 ]; then
    curl -s "$1"
fi
