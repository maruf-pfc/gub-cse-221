import pandas as pd

# Your details
data = {
    "ID": ["YOUR_ID"],
    "Name": ["YOUR_NAME"]
}

# Create dataframe
df = pd.DataFrame(data)

# Save as CSV
df.to_csv("student_info.csv", index=False)

print("CSV file created successfully!")
