package com.example.first_app

import android.animation.ObjectAnimator
import android.os.Bundle
import android.widget.ImageView
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val textView = findViewById<TextView>(R.id.textView)
        val imageView = findViewById<ImageView>(R.id.imageView)

        // Change text dynamically
        textView.text = "Hi my name is Milinda!"

        // Simple bounce animation
        ObjectAnimator.ofFloat(imageView, "translationY", 0f, 300f).apply {
            duration = 1000
            repeatCount = ObjectAnimator.INFINITE
            repeatMode = ObjectAnimator.REVERSE
            start()
        }
    }
}
