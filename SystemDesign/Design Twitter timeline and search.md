# Design the Twitter timeline and search
## Use cases

* User posts a tweet
    - Server pushes it to user's followers
* User views his/her own timeline(own tweets)
* User views home timeline(posts of other users)
* User searches keywords

Out of scope:

* Service pushes tweets to streams
* Service strips out tweets based on user's visibility settings
* Analytics

## Constraints and assumptions:
General:

* Traffic not evenly distributed
* User should be able to see one's own tweet quickly
    - Delay allowed before other users see it
* 100 million active users
* 500 million tweets per day or 15 billion tweets per month
    - Each tweet averages a fanout of 10 deliveries
    - 5 billion total tweets delivered on fanout per day
    - 150 billion tweets delivered on fanout per month
* 250 billion read requests per month
* 10 billion searches per month

Timeline:

* Viewing the timeline should be fast
* More read than writes

## Usage estimation
