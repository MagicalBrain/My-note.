# MobaXterm远程GUI程序

## 显示图像

远程运行opencv的程序并显示图片没有问题。

## 显示视频

远程运行realsense相机sdk打开相机，显示相机的实时图像没有问题

## 显示点云

目前我尝试使用这个工具来运行pcl程序并显示点云，但是不行，原因未知，报错信息：

```bash
libGL error: MESA-LOADER: failed to open swrast (search paths /usr/lib/aarch64-linux-gnu/dri:\$${ORIGIN}/dri:/usr/lib/dri)
libGL error: failed to load driver: swrast
XIO:  fatal IO error 11 (Resource temporarily unavailable) on X server "localhost:10.0"
      after 58 requests (58 known processed) with 16 events remaining.
```

### wsl2 显示点云依然会有问题

```bash
./bin/pcl_test
Test PCL !!!
ERROR: In /build/vtk7-yd0MKW/vtk7-7.1.1+dfsg2/Rendering/OpenGL2/vtkOpenGLRenderWindow.cxx, line 636
vtkXOpenGLRenderWindow (0x556aed9d25d0): GL version 2.1 with the gpu_shader4 extension is not supported by your graphics driver but is required for the new OpenGL rendering backend. Please update your OpenGL driver. If you are using Mesa please make sure you have version 10.6.5 or later and make sure your driver in Mesa supports OpenGL 3.2.

X connection to localhost:10.0 broken (explicit kill or server shutdown).
```
