import tweepy
from textblob import TextBlob

# Step 1 - Authenticate
consumer_key= 'RFCTIkTXT3YzLy0eg0nzjKD8u'
consumer_secret= 'Yka94MBlShOVb5CsPKtcllWfGFEZmfi0YolSR5z8H6cFJLpdCl'

access_token='542539112-NUQboit42r1gstORlpAwTZcOOeC1pwrqPXtWtVq8'
access_token_secret='j3Rb4J1GwhIEXKK0NYUyfnCgasWtAluof5WxAijymydrL'

auth = tweepy.OAuthHandler(consumer_key, consumer_secret)
auth.set_access_token(access_token, access_token_secret)

api = tweepy.API(auth)

#Step 3 - Retrieve Tweets
print("Enter Search Key :")
key = input()
public_tweets = api.search(key,count=100)

neutral = 0
negative = 0
positive = 0


#CHALLENGE - Instead of printing out each tweet, save each Tweet to a CSV file
#and label each one as either 'positive' or 'negative', depending on the sentiment 
#You can decide the sentiment polarity threshold yourself


for tweet in public_tweets:
    print(tweet.text)
    
    #Step 4 Perform Sentiment Analysis on Tweets
    analysis = TextBlob(tweet.text)
    print(analysis.sentiment)
    if(analysis.sentiment.polarity > 0 ):
        positive += 1
    elif (analysis.sentiment.polarity < 0):
        negative += 1
    else:
        neutral += 1
    print("")

total = positive + negative + neutral
print("Positive \t: {}%\nNegative \t: {}%\nNeutral \t:{}%\n".format(positive,negative,neutral))