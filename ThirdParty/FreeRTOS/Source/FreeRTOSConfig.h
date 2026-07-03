 /*
  * FreeRTOS Kernel V10.x.x
  * Configuration file for TM4C123GXL (ARM Cortex-M4F)
  *
  * Based on official FreeRTOS documentation
  */

 #ifndef FREERTOSCONFIG_H
 #define FREERTOSCONFIG_H

 /*-----------------------------------------------------------
  * Application specific definitions.
  *
  * These definitions should be adjusted for your particular hardware and
  * application requirements.
  *----------------------------------------------------------*/

 /* ===== MANDATORY CONFIGURATION PARAMETERS ===== */

 /* Set configUSE_PREEMPTION to 1 to use preemptive scheduling,
    0 for cooperative scheduling. */
 #define configUSE_PREEMPTION                    1

 /* Set to 1 to use 32-bit tick type, 0 for 16-bit tick type.
    MANDATORY PARAMETER - Must be defined! */
 #define configUSE_16_BIT_TICKS                  0

 /* Set configUSE_PORT_OPTIMISED_TASK_SELECTION to 1 for faster task selection
    on ARM Cortex-M (recommended). */
 #define configUSE_PORT_OPTIMISED_TASK_SELECTION 1

 /* ===== CLOCK AND TICK CONFIGURATION ===== */

 /* The frequency of the tick in Hertz (Hz).
    TM4C123GXL typical: 1000Hz for responsive systems. */
 #define configTICK_RATE_HZ                      1000

 /* CPU clock frequency in Hz (TM4C123GXL runs at 80MHz) */
 #define configCPU_CLOCK_HZ                      80000000UL

 /* ===== TASK AND PRIORITY CONFIGURATION ===== */

 /* The maximum number of task priorities.
    Valid priority numbers: 0 (lowest) to (configMAX_PRIORITIES - 1) (highest).
    ARM Cortex-M4 has 16 interrupt priority levels. */
 #define configMAX_PRIORITIES                    5

 /* The minimum stack size (in words) for any task.
    For Cortex-M4: minimum 128 words recommended. */
 #define configMINIMAL_STACK_SIZE                128

 /* Stack depth type */
 #define configSTACK_DEPTH_TYPE                  uint32_t

 /* ===== MEMORY CONFIGURATION ===== */

 /* Total heap size in bytes for dynamic memory allocation.
    TM4C123GXL has 32KB SRAM. Allocate carefully:
    - Heap: ~16KB
    - Task stacks: ~12KB
    - Other: remaining */
 #define configTOTAL_HEAP_SIZE                   16384

 /* Which heap implementation to use:
    1 = heap_1.c (simplest, never frees)
    2 = heap_2.c (allows freeing, fragmentation)
    3 = heap_3.c (uses malloc/free)
    4 = heap_4.c (coalescing, recommended)
    5 = heap_5.c (multiple regions) */
 #define configFREERTOS_MEMORY_SCHEME            4

 /* ===== HOOK FUNCTIONS ===== */

 /* Set to 1 if you implement vApplicationIdleHook() */
 #define configUSE_IDLE_HOOK                     0

 /* Set to 1 if you implement vApplicationTickHook() */
 #define configUSE_TICK_HOOK                     0

 /* Set to 1 if you implement vApplicationMallocFailedHook() */
 #define configUSE_MALLOC_FAILED_HOOK            0

 /* ===== KERNEL FEATURES ===== */

 /* Set to 1 to enable task suspend/resume functions */
 #define configUSE_SUSPEND_RESUME_FUNCTION       1

 /* Set to 1 to include event groups */
 #define configUSE_EVENT_GROUPS                  1

 /* Set to 1 to include binary and counting semaphores */
 #define configUSE_COUNTING_SEMAPHORES           1

 /* Set to 1 to include mutexes and priority inheritance */
 #define configUSE_MUTEXES                       1

 /* Set to 1 to include recursive mutexes */
 #define configUSE_RECURSIVE_MUTEXES             1

 /* Set to 1 to include queue sets */
 #define configUSE_QUEUE_SETS                    0

 /* Set to 1 to enable task notifications */
 #define configUSE_TASK_NOTIFICATIONS            1

 /* Set to 1 to enable application task tags */
 #define configUSE_APPLICATION_TASK_TAG          0

 /* Number of thread-local storage pointers */
 #define configNUM_THREAD_LOCAL_STORAGE_POINTERS 0

 /* ===== SOFTWARE TIMERS ===== */

 /* Set to 1 to include software timers */
 #define configUSE_TIMERS                        1

 /* Priority of the timer service task */
 #define configTIMER_TASK_PRIORITY               3

 /* Stack size (in words) for the timer service task */
 #define configTIMER_TASK_STACK_DEPTH            256

 /* Queue length for timer commands */
 #define configTIMER_QUEUE_LENGTH                10

 /* Set to 1 if vApplicationDaemonTaskStartupHook is implemented */
 #define configUSE_DAEMON_TASK_STARTUP_HOOK      0

 /* ===== TRACE AND STATISTICS ===== */

 /* Set to 1 to include trace facility for debugging */
 #define configUSE_TRACE_FACILITY                1

 /* Set to 1 to enable runtime statistics collection */
 #define configGENERATE_RUN_TIME_STATS            0

 /* Set to 1 to enable statistics formatting functions */
 #define configUSE_STATS_FORMATTING_FUNCTIONS    0

 /* Set to 1 to include xTaskGetSchedulerState() */
 #define configUSE_GET_TASK_STATE                0

 /* ===== DEBUG CONFIGURATION ===== */

 /* Set to 1 to enable stack overflow checking:
    1 = canary value check
    2 = stack limit check */
 #define configCHECK_FOR_STACK_OVERFLOW          0

 /* Custom assert macro for kernel assertions */
 #define configASSERT( x ) if( ( x ) == 0 ) { taskDISABLE_INTERRUPTS(); for( ;; ); }

 /* Set to 1 to enable task cleanup callbacks */
 #define configUSE_TASK_CLEAN_UP_CALLBACKS       0

 /* ===== MEMORY ALLOCATION ===== */

 /* Set to 1 to support static memory allocation */
 #define configSUPPORT_STATIC_ALLOCATION         0

 /* Set to 1 to support dynamic memory allocation */
 #define configSUPPORT_DYNAMIC_ALLOCATION        1

 /* ===== LOW POWER / TICKLESS IDLE ===== */

 /* Set to 1 to enable tickless idle mode (power saving) */
 #define configUSE_TICKLESS_IDLE                 0

 /* ===== RUNTIME STATS ===== */

 /* Type used for runtime stats counters */
 #define configRUN_TIME_COUNTER_TYPE             uint32_t

 /* ===== ARM CORTEX-M4 PORT SPECIFIC CONFIGURATION ===== */

 /* CRITICAL: Interrupt priority for kernel (SysTick and SVC).
    Must be at the LOWEST priority level.
    For TM4C123GXL (8-bit priorities): 255 (0xFF) */
 #define configKERNEL_INTERRUPT_PRIORITY         255

 /* Maximum interrupt priority that can call FreeRTOS API functions.
    Interrupts with priority equal to or higher (numerically lower) than this
    value cannot call FreeRTOS API functions.

    For TM4C123GXL: Set to 191 (bits 7:5 = 101b, shifts to 0xA0 in NVIC)
    This allows interrupts 0-4 to call FreeRTOS APIs. */
 #define configMAX_SYSCALL_INTERRUPT_PRIORITY    191

 /* Used to set the priority of individual interrupts that use the FreeRTOS API */
 #define configMAX_API_CALL_INTERRUPT_PRIORITY   5

 #define configTIMER_SERVICE_TASK_NAME 0

 /* ===== TIME SLICING ===== */

 /* Set to 1 to enable time slicing between equal priority tasks */
 #define configUSE_TIME_SLICING                  1

 #define INCLUDE_xTaskGetIdleTaskHandle 1
 #define INCLUDE_pxTaskGetStackStart    1

 /* ===== SEGGER SYSTEMVIEW INTEGRATION ===== */
 #include "SEGGER_SYSVIEW_FreeRTOS.h"

 #endif /* FREERTOSCONFIG_H */
