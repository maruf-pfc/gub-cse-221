from transformers import pipeline

# Allocate a pipeline for sentiment-analysis
classifier = pipeline('sentiment-analysis')

res = classifier(
    [
        'I Love Parmanent Campus but hate City Campus', 
        'Football is my favorite sport', 
        'CSE te cgpa fact kore na, skill e main'
    ]
)

for r in res:
    print(f"label: {r['label']}, with score: {round(r['score'], 4) * 100}%")