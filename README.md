# dummy_learn

创建工程时钟树记得选择HSE

因为要用freertos，所以timebase source要选tim

安全性：adc要选temperature sensor channel 读取内部温度传感器

带内部参考电压（VREFINT）校正的STM32 DMA 内置温度采集

adc惯例选择规则组，惯例选完adc要重配时钟树

tim encoder mode input filter ?

tim10自动装载开了，tim11没开？

spi1中断开了，spi3没开？

注意usrt4的RX dma是circular

freertos选择ENABLE_FPU，各参数配置

生成界面修改Linker Settings

软件版本：cubemx:6.14.0 keil:5.2.4 pack:2.17.1