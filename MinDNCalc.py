ReadNoise = float(input("Enter your Read Noise: "))
Gain = float(input("Enter your Gain in e-/ADU: "))
BiasOffset = int(input("Enter your Bias Offset in ADU: "))
Bits = int(input("Enter the Bit Depth of the Camera: "))
Factor = int((input("Enter your preferred Swamping Factor: ")))
Swamp = pow(ReadNoise, 2) * Factor
MinDN16 = int(((Swamp / Gain) + BiasOffset) * pow(16, 2) / pow(Bits, 2))
print ("Minimum Exposure in 16-bit ADU:", MinDN16)

