from matplotlib import pyplot as plt
import numpy as np
import pandas as pd
from matplotlib import animation
from matplotlib import rcParams

rcParams['animation.convert_path'] = r'/usr/bin/convert'

fig = plt.figure()
ax = fig.add_subplot(projection='3d')

def update(num, data, ax):
    
    ax.clear()
    
    ax.set_xlim3d([0, 10.0])
    ax.set_xlabel('X')
    
    ax.set_ylim3d([0, 10.0])
    ax.set_ylabel('Y')
    
    ax.set_zlim3d([0.0, 10.0])
    ax.set_zlabel('Z')

    phi = np.linspace(0, np.pi, 100)
    theta = np.linspace(0, 2 * np.pi, 100)
    phi, theta = np.meshgrid(phi, theta)
    
    file_name = str(num) + ".csv"
    
    data = pd.read_csv(file_name)
    
    for i in range(len(data)):
        cord = data.iloc[i]
        x = cord.iloc[0] + cord.iloc[3] * np.sin(phi) * np.cos(theta)
        y = cord.iloc[1] + cord.iloc[3] * np.sin(phi) * np.sin(theta)
        z = cord.iloc[2] + cord.iloc[3] * np.cos(phi)
        color = 'r' if cord.iloc[4] else 'b'
        ax.plot_surface(x, y, z,  rstride=4, cstride=4, color=color, linewidth=0, alpha=0.5)

N = 0
with open("info") as file:
    line = file.readline()
    N = int(line)

ani = animation.FuncAnimation(fig, update, N, fargs=(data, ax), interval=10000/N, blit=False)
ani.save('bubble.gif', writer='imagemagick')
plt.show()
