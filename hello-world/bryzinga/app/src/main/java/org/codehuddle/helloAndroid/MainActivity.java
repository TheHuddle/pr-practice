package org.codehuddle.helloAndroid;

import androidx.annotation.RequiresApi;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.AppCompatEditText;
import androidx.appcompat.widget.AppCompatTextView;

import android.os.Build;
import android.os.Bundle;
import android.os.Handler;
import android.text.Html;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.TextView;

import java.util.Locale;
import java.util.Random;
import java.util.concurrent.atomic.AtomicReference;

public class MainActivity extends AppCompatActivity {
    boolean stop;

    @RequiresApi(api = Build.VERSION_CODES.N)
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        AppCompatEditText editText = findViewById(R.id.text_to_generate);
        AppCompatEditText textColor = findViewById(R.id.text_color);
        AppCompatEditText textSize = findViewById(R.id.text_size);

        CheckBox bold = findViewById(R.id.bold_checkbox);
        CheckBox italic = findViewById(R.id.italic_checkbox);
        CheckBox strike = findViewById(R.id.strike_checkbox);
        CheckBox underline = findViewById(R.id.underline_checkbox);

        Button generateButton = findViewById(R.id.button);
        TextView textView = findViewById(R.id.generating_text);
        AtomicReference<String> generate = new AtomicReference<>("");

        generateButton.setOnClickListener(v -> {
            if (generateButton.getText().toString().toLowerCase(Locale.ROOT).equals("start")) {
                if (editText.getText().toString().equals("")) {
                    editText.setText("Hello World!");
                }
                textView.setTextSize(14);
                textView.setText("Generating text... press \"STOP\" to view final result.");
                stop = false;
                generateButton.setText("stop");
                new Thread(() -> {
                    while(!stop) {
                        try {
                            Thread.sleep(10);
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }

                        String colorCode;
                        String before = "";
                        String after = "";
                        if (textColor.getText().toString().equals("")) {
                            Random random = new Random();
                            int nextInt = random.nextInt(0xffffff + 1);

                            colorCode = String.format("#%06x", nextInt);
                        } else {
                            colorCode = textColor.getText().toString();
                        }
                        if (bold.isChecked()) {
                            before = "<strong>";
                            after = "</strong>";
                        }
                        if (italic.isChecked()) {
                            before = before + "<em>";
                            after = after + "</em>";
                        }
                        if (strike.isChecked()) {
                            before = before + "<del>";
                            after = after + "</del>";
                        }
                        if (underline.isChecked()) {
                            before = before + "<u>";
                            after = after + "</u>";
                        }
                        generate.set(generate + before + "<font color='" + colorCode + "' >" + editText.getText() + " </font>" + after);
//                        generate.set(generate + "<h1 style='display:inline'>Hello World!</h1>");
                    }
                }).start();

            } else {
                stop = true;
                if (!textSize.getText().toString().equals("")) {
                    textView.setTextSize(Float.parseFloat(textSize.getText().toString()));
                }
                generateButton.setText("start");
                textView.setText(Html.fromHtml(String.valueOf(generate)));
                generate.set("");
            }
        });
    }
}