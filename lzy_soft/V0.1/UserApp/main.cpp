#include "common_inc.h"

osSemaphoreId sem_usb_irq;
osSemaphoreId sem_uart4_dma;
osSemaphoreId sem_uart5_dma;
osSemaphoreId sem_usb_rx;
osSemaphoreId sem_usb_tx;
osSemaphoreId sem_can1_tx;
osSemaphoreId sem_can2_tx;

void user_freertos_init()
{
    // Init usb irq binary semaphore, and start with no tokens by removing the starting one.
    osSemaphoreDef(sem_usb_irq);
    sem_usb_irq = osSemaphoreNew(1, 0, osSemaphore(sem_usb_irq));

    // Create a semaphore for UART DMA and remove a token
    osSemaphoreDef(sem_uart4_dma);
    sem_uart4_dma = osSemaphoreNew(1, 1, osSemaphore(sem_uart4_dma));
    osSemaphoreDef(sem_uart5_dma);
    sem_uart5_dma = osSemaphoreNew(1, 1, osSemaphore(sem_uart5_dma));

    // Create a semaphore for USB RX, and start with no tokens by removing the starting one.
    osSemaphoreDef(sem_usb_rx);
    sem_usb_rx = osSemaphoreNew(1, 0, osSemaphore(sem_usb_rx));

    // Create a semaphore for USB TX
    osSemaphoreDef(sem_usb_tx);
    sem_usb_tx = osSemaphoreNew(1, 1, osSemaphore(sem_usb_tx));

    // Create a semaphore for CAN TX
    osSemaphoreDef(sem_can1_tx);
    sem_can1_tx = osSemaphoreNew(1, 1, osSemaphore(sem_can1_tx));
    osSemaphoreDef(sem_can2_tx);
    sem_can2_tx = osSemaphoreNew(1, 1, osSemaphore(sem_can2_tx));
}

/* Thread Definitions -----------------------------------------------------*/
osThreadId_t controlLoopFixUpdateHandle;
void ThreadControlLoopFixUpdate(void *argument)
{
    for (;;)
    {
    }
}

/* Default Entry -------------------------------------------------------*/
void Main(void)
{

    user_freertos_init();

    InitCommunication();


    // Init & Run User Threads.
    const osThreadAttr_t controlLoopTask_attributes = {
        .name = "ControlLoopFixUpdateTask",
        .stack_size = 2000,
        .priority = (osPriority_t)osPriorityRealtime,
    };
    controlLoopFixUpdateHandle = osThreadNew(ThreadControlLoopFixUpdate, nullptr,
                                             &controlLoopTask_attributes);
}