import pandas as pd
from datetime import datetime
import matplotlib.pyplot as plt


custom_date_parser = lambda x: datetime.strptime(x, "%d-%m-%Y %H:%M_%S.%f")

df = pd.read_csv('results.csv',  parse_dates=['Timestamp'], date_parser=custom_date_parser)
df2 = df.info()
print(df2)

df.plot(x='Timestamp', y='Mean_values')
plt.title('Rapid Light Curve', color='black')
plt.tight_layout()
plt.show()