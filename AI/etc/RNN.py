from tensorflow.python.keras.layers import SimpleRNN
from tensorflow.python.keras.models import Sequential

model = Sequential()
model.add(SimpleRNN(hidden_units))