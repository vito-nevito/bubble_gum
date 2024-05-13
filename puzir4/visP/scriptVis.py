from matplotlib import pyplot as plt
import numpy as np
from mpl_toolkits.mplot3d import Axes3D
from matplotlib import animation

import pandas as pd
from matplotlib import rcParams

rcParams['animation.convert_path'] = r'/usr/bin/convert'

fig = plt.figure()
ax = fig.add_subplot(projection='3d')

data = 1

def update(num, ax, lenRoom, point):
    
    ax.clear()
    
    ax.set_xlim3d([0, lenRoom[0]])
    ax.set_xlabel('X')
    
    ax.set_ylim3d([0, lenRoom[1]])
    ax.set_ylabel('Y')
    
    ax.set_zlim3d([0.0, lenRoom[2]])
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
        
    ax.scatter(point[0], point[1], point[2], color='g', s=50)
    ax.set_title(f"Step {num}")

N = 0
lenRoom = 0
point = 0
with open("info") as file:
    line = file.readline()
    N = int(line)
    line = file.readline()
    point = list(map(float, line.split()))
    line = file.readline()
    lenRoom = list(map(float, line.split()))



ani = animation.FuncAnimation(fig, update, N, fargs = (ax, lenRoom, point), interval=10000/N, blit=False)
ani.save('bubble.gif', writer='imagemagick')
plt.show()
