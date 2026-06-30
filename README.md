# Guitar Audio DSP Pipeline

A discrete-time parallel audio multi-effects pipeline designed in Simulink and compiled into optimized, production-ready C++ code. The system mimics a hardware guitar pedalboard matrix, splitting an incoming guitar instrument signal (via an ADC interface) into four parallel effects units before mixing down the final signal.

---
🔌 Signal Origin: LTSpice Integration
---
Rather than using a generic math functio, the input signal for this project represents a real-world analog guitar waveform. A physical analog guitar preamp circuit was simulated in LTSpice to capture realistic electrical behavior. This continuous-time voltage trace was then exported and imported directly into the Simulink architecture as the raw test stimulus (guitar_adc).


## 🎸 The Pedalboard Architecture

The processing pipeline operates at a strict **8 kHz sampling rate** (Fixed-Step size = 1/8000 s or 125 microseconds per sample tick). The core architecture acts like a parallel multi-effects rig split into 4 distinct pedal circuits:

### 1. Tone / Graphic EQ Circuit (Discrete Filter Block)
* **Guitar Pedal Equivalent:** A standard graphic equalizer pedal or the **Tone Knob** on a classic drive box.
* **DSP Implementation:** A digital IIR single-pole filter with a denominator configured to `[1 -0.6]`. This positions a stable pole inside the unit circle ($z = 0.6$).
* **Acoustic Behavior:** It averages out rapid high-frequency signal shifts, acting as a low-pass filter. On a real pedalboard, this replicates rolling the tone knob to the left to tame harsh pick attack and create a warmer, darker jazz-rock timbre.

### 2. Overdrive / Fuzz Box (Saturation Block)
* **Guitar Pedal Equivalent:** An **Ibanez Tube Screamer** or a **BOSS DS-1 Distortion**.
* **DSP Implementation:** Dynamic range amplitude clamping restricted strictly between `[-0.15V, 0.15V]`.
* **Acoustic Behavior:** This block simulates analog **hard clipping**. In a traditional analog pedal, operational amplifiers push an audio signal past the threshold of silicon clipping diodes to slice off the wave peaks. Digitally, limiting the voltage threshold forces mathematical clipping, generating rich harmonic distortion and giving the guitar its gritty, driven crunch.

### 3. Slapback Echo Unit (Discrete Delay Block)
* **Guitar Pedal Equivalent:** A vintage **Digital Delay Pedal** (e.g., BOSS DD-3).
* **DSP Implementation:** A discrete time-domain shift matrix configured to $z^{-16}$.
* **Acoustic Behavior:** Digital delays operate using a circular RAM memory buffer. The circuit samples a guitar note, holds it in a queue, and feeds it back after a precise duration. At an 8 kHz sample clock, a 16-sample delay shifts the sound wave exactly 2 ms later, creating a tight, instantaneous classic slapback echo effect.

### 4. Ambient Hall Reverb (Reverb Block)
* **Guitar Pedal Equivalent:** An acoustic **Space/Hall Reverb Pedal**.
* **DSP Implementation:** A discrete feedback accumulation network.
* **Acoustic Behavior:** Reverb creates the sonic illusion of playing in an expansive physical environment (like a cathedral or concrete room). It accomplishes this by taking delayed audio signals and continuously routing a controlled portion of them back into the input loop.

---

## 🎛️ Digital Audio Characteristics: Understanding the Steps

The output wave exhibits a distinctive **stair-step pattern** on simulation scopes. This is the authentic textbook representation of a discrete digital signal holding its computed voltage state stable over each 125 microsecond CPU clock cycle before the next sample arrives. 

Operating at a vintage **8 kHz sample rate**, the system natively captures frequencies up to a 4 kHz Nyquist limit. This processing creates a lo-fi, bit-crushed character reminiscent of legendary 1980s retro digital effects rack units.

---

## 💻 Code Generation & Deployment

* **Target Language:** Standard Embedded C++
* **System Target File:** `ert.tlc` (Embedded Real-Time Target via Embedded Coder)
* **Optimizations:** Stripped completely of continuous analog simulation overhead, producing bare-metal, lightweight functions optimized for direct deployment inside the execution loop of a modern audio microcontroller (e.g., STM32, ESP32, Teensy, or Texas Instruments DSPs).
