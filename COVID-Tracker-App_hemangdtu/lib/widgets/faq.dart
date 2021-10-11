import 'package:covid_tracker/constants/textData.dart';
import 'package:flutter/material.dart';

class FAQPage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('FAQs'),
      ),
      body: ListView.builder(
          itemCount: TextData.questionAnswers.length,
          itemBuilder: (context, index) {
            return ExpansionTile(
              title: Text(
                TextData.questionAnswers[index]['question'],
                style: TextStyle(fontWeight: FontWeight.bold),
              ),
              children: <Widget>[
                Padding(
                  padding: const EdgeInsets.all(12.0),
                  child: Text(TextData.questionAnswers[index]['answer']),
                )
              ],
            );
          }),
    );
  }
}
