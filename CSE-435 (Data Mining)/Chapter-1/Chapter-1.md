# Chapter 1

## 1. Why Data Mining — Detailed

Definition: Data mining is the automated (or semi-automated) process of discovering non-trivial, implicit, previously unknown and potentially useful information from large databases. The aim is actionable knowledge.
Detailed explanation: Data is generated in huge volumes (transactions, sensors, logs). Raw data alone is not useful — we need patterns, trends, exceptions. Data mining uses statistical methods, machine learning, pattern recognition, and database techniques to extract these patterns.
Functions: classification, regression, clustering, association rule mining, anomaly detection, summarization.
Business value: improving decisions, personalization (recommendations), anomaly/fraud detection, segmentation, forecasting.
Example (practical): Market-basket analysis: find {bread, butter} → {jam} with support/confidence — use for promotions. Fraud detection: anomaly detection on credit card transactions.
Pitfalls to mention in exam: overfitting, spurious correlations, privacy issues, data quality dependence.
Exam Q (4 marks): Define data mining and list four applications.
Model Answer: One-line definition + apps (market-basket, fraud detection, churn prediction, recommender systems).
Exam Q (8 marks): Explain how data mining adds value to business decisions. Give 2 concrete examples.
Model Answer: 2–3 paragraphs: describe decision automation & examples (recommendation increases AOV; fraud detection reduces losses).

## ১. কেন Data Mining — বিস্তারিত ব্যাখ্যা

সংজ্ঞা: Data mining হল বড় ডেটাবেস থেকে স্বয়ংক্রিয় বা অর্ধ-স্বয়ংক্রিয়ভাবে অপ্রচলিত, পূর্বে অজানা এবং ব্যবহারযোগ্য তথ্য আবিষ্কারের প্রক্রিয়া। উদ্দেশ্য হলো প্রয়োগযোগ্য জ্ঞান বের করা।
বিস্তৃত ব্যাখ্যা: লেনদেন, সেন্সর, লগ—ডাটা অত্যাধিক পরিমাণে তৈরি হয়। কাঁচা ডাটা সরাসরি কাজে লাগে না; প্যাটার্ন, ট্রেন্ড ও অস্বাভাবিকতা প্রয়োজন। ডাটা মাইনিং পরিসংখ্যান, মেশিন লার্নিং, প্যাটার্ন রিকগনিশন ও ডাটাবেস টেকনিক ব্যবহার করে এগুলো বের করে।
ফাংশনসমূহ: classification, regression, clustering, association rule mining, anomaly detection, summarization।
ব্যবসায় মূল্য: সিদ্ধান্ত গ্রহণ উন্নত করে, পার্সোনালাইজেশন (রেকমেন্ডেশন), জালিয়াতি শনাক্তকরণ, গ্রাহক বিভাগ, পূর্বাভাস।
উদাহরণ: মার্কেট-বাস্কেট এনালাইসিস: {bread, butter} → {jam} নিয়ম পাওয়া; Fraud detection: আদ্যত অনাকাঙ্খিত ট্রানজ্যাকশন চিহ্নিত করা।
পরীক্ষায় উল্লেখ্য ভুলধারণা: overfitting, মিথ্যা correlation, প্রাইভেসি সমস্যা, ডাটা কোয়ালিটির উপর নির্ভরশীলতা।
পরীক্ষা প্রশ্ন (৪ মার্ক): Data mining সংজ্ঞা বলো ও ৪টি প্রয়োগ দাও।
মডেল উত্তর: সংজ্ঞা + প্রয়োগ (market-basket, fraud detection, churn prediction, recommender)।
পরীক্ষা প্রশ্ন (৮ মার্ক): কীভাবে data mining ব্যবসায় মান যোগ করে? ২টি বাস্তব উদাহরণ দাও।
মডেল উত্তর: ২ প্যারায় decision automation + উদাহরণ।

## 2. OLAP vs OLTP — Exhaustive Comparison

OLTP (Online Transaction Processing): transactional systems; many concurrent short transactions (insert/update/delete); ACID properties; normalized schema; day-to-day operations. Example: bank withdraw, order entry.
OLAP (Online Analytical Processing): analytical, read-heavy, complex queries, historical data, denormalized star/snowflake schema, support roll-up/drill-down. Example: monthly sales trend, customer LTV.
Details to mention in exam: schema differences, indexing strategies (OLTP secondary indexes vs OLAP materialized views & aggregate tables), backup/latency concerns.
OLAP operations (must know + short examples): roll-up (aggregate data e.g., daily→monthly), drill-down (month→day), slice (select single dimension value), dice (select subcube on multiple dims), pivot (rotate dimensions).
Exam Q (6 marks): Compare OLTP and OLAP in a table and explain roll-up & drill-down with examples.
Model Answer: 6-row table + two OLAP operations with examples.

## ২. OLAP বনাম OLTP — বিস্তৃত তুলনা

OLTP: লেনদেন-ভিত্তিক সিস্টেম; অনেক কনকারেন্ট ছোট ট্রানজ্যাকশন (insert/update/delete); ACID অপরিহার্য; নর্মালাইজড স্কিমা; দৈনন্দিন অপারেশন। উদাহরণ: ব্যাংকের টাকা উত্তোলন, অনলাইন অর্ডার এন্ট্রি।
OLAP: বিশ্লেষণাত্মক, বেশি পড়ার (read-heavy), জটিল কুয়েরি, ঐতিহাসিক ডাটা, ডিনর্মালাইজড star/snowflake স্কিমা; roll-up/drill-down সাপোর্ট করে। উদাহরণ: মাসিক বিক্রয় ট্রেন্ড, কাস্টমার LTV বিশ্লেষণ।
পরীক্ষায় উল্লেখ করার মত বিষয়: স্কিমা পার্থক্য, ইনডেক্সিং (OLTP তে দ্রুত secondary index; OLAP এ materialized views ও aggregates), ব্যাকআপ ও লেটেন্সি বিষয়ক পার্থক্য।
OLAP অপারেশন (উদাহরণসহ): roll-up (aggregation: দৈনিক→মাসিক), drill-down (বিস্তারিত: মাস→দিন), slice (এক ডাইমেনশনের নির্দিষ্ট মান), dice (একাধিক ডাইমেনশনে সাব-কিউব), pivot (ডাইমেনশন রোটেট)।
পরীক্ষা প্রশ্ন (৬ মার্ক): OLTP ও OLAP টেবিল আকারে তুলনা করো এবং roll-up ও drill-down উদাহরণ দাও।
মডেল উত্তর: ৬-সারি টেবিল + দুইটি অপারেশন উদাহরণসহ।

## 3. KDD Steps (7 steps) — In-depth + Techniques + Examples

List & Explain:

1. Data Cleaning: missing value handling (mean/mode/median imputation, k-NN imputation), noise removal (smoothing, binning), outlier detection (z-score, IQR).
2. Data Integration: schema matching, resolving entity IDs, conflict handling, deduplication.
3. Data Selection: choosing relevant attributes, instances, time windows. E.g., select last 12 months transactions.
4. Data Transformation: normalization (min-max, z-score), discretization (equal-width, equal-frequency), aggregation (daily→monthly), feature construction (RFM), dimensionality reduction (PCA).
5. Data Mining: choose algorithms (decision trees, SVM, k-means, Apriori, FP-Growth), parameter selection, cross-validation.
6. Pattern Evaluation: objective measures (accuracy, precision/recall, support/confidence/lift), statistical tests (chi-square, p-value), remove redundant patterns.
7. Knowledge Presentation: visualization (bar/line/heatmap), reports, rule lists, executive summaries; deploy models (APIs, dashboards).
   Concrete example (E-commerce): show mapping — cleaning → integrate CRM + transactions → select active customers → transform to RFM → PCA/feature selection → cluster (k-means) → association mining (Apriori) per cluster → evaluate lift & significance → present top-10 actionable rules in dashboard.
   Exam Q (10 marks): Explain the 7 KDD steps and give one technique and one example for each step.
   Model Answer: 7-point list with 1-line technique & 1-line example per step.

## ৩. KDD ৭ ধাপ — বিশদ + টেকনিক + উদাহরণ

ধাপসমূহ ও ব্যাখ্যা:

1. Data Cleaning: মিসিং ভ্যালু ইম্পুট (mean/median/mode বা k-NN), noise কমানো (smoothing/binning), আউটলার চিহ্নিতকরণ (z-score, IQR)।
2. Data Integration: স্কিমা মিলানো, entity resolution (এক কাস্টমার বিভিন্ন ID), কনফ্লিক্ট সমাধান, ডুপ্লিকেট রিমুভ।
3. Data Selection: প্রাসঙ্গিক এট্রিবিউট/ইনস্ট্যান্স/সময় বাছাই (যেমন শেষ ১২ মাস)।
4. Data Transformation: normalization (min-max, z-score), discretization (equal-width, equal-frequency), aggregation (দিন→মাস), ফিচার কনস্ট্রাকশন (RFM), dimension reduction (PCA)।
5. Data Mining: অ্যালগরিদম নির্বাচন (decision tree, SVM, k-means, Apriori), প্যারামিটার টিউনিং, cross-validation।
6. Pattern Evaluation: মেট্রিক (accuracy, precision/recall, support/confidence/lift), স্ট্যাটিস্টিকাল টেস্ট (chi-square, p-value), redundant pattern ফিল্টার।
7. Knowledge Presentation: ভিজ্যুয়ালাইজেশন (বার, লাইন, হিটম্যাপ), রিপোর্ট, রুল লিস্ট, executive summary; মডেল ডেপ্লয় (API, ড্যাশবোর্ড)।
   E-commerce উদাহরণ (ম্যাপিং): ক্লিনিং → CRM+ট্রানজ্যাকশন ইন্টিগ্রেট → active কাস্টমার সিলেকশন → RFM ফিচার → PCA/ফিচার সিলেকশন → কাস্টমার ক্লাস্টারিং (k-means) → প্রতিটি ক্লাস্টারে association mining (Apriori) → lift ও significance যাচাই → টপ-১০ actionable রুল ড্যাশবোর্ডে।
   পরীক্ষা প্রশ্ন (১০ মার্ক): KDD ৭ ধাপ ব্যাখ্যা করো ও প্রতিটি ধাপের জন্য ১টি পদ্ধতি ও ১টি উদাহরণ বলো।
   মডেল উত্তর: সাতটি ধাপ ক্রমানুসারে, প্রতিটির জন্য ১ লাইনের টেকনিক ও ১ লাইনের উদাহরণ।

## 4. Data Warehouses — Full explanation + schema + ETL details

Definition (academic): A data warehouse is a subject-oriented, integrated, time-variant and non-volatile collection of data supporting management’s decision-making process.
Characteristics to list in exam: subject-oriented, integrated, time-variant, non-volatile.
Schemas: star schema (fact table + denormalized dims), snowflake (normalized dims). Provide tiny star example: Fact_Sales(order_id, date_id, product_id, store_id, qty, revenue) + Date(date_id, day, month, year) + Product(product_id, name, category) + Store(store_id, city, region).
ETL details: Extract (from OLTP/CSV/Logs), Transform (clean, conform, aggregate), Load (initial bulk load or incremental). Mention slowly changing dimensions (Type 1/2/3) briefly.
Why used: unifies data, historical analysis, speeds up analytical queries, supports OLAP cubes.
Exam Q (6 marks): Define a data warehouse and draw a star schema for sales.
Model Answer: definition + small schema diagram/table.

## ৪. Data Warehouse — পূর্ণ ব্যাখ্যা + স্কিমা + ETL বিস্তারিত

সংজ্ঞা (একাডেমিক): Data warehouse হলো বিষয়-ভিত্তিক, ইন্টিগ্রেটেড, টাইম-ভেরিয়েন্ট এবং নন-ভোলাটাইল ডেটার সংগ্রহ যা ম্যানেজমেন্ট সিদ্ধান্ত গ্রহণকে সাপোর্ট করে।
পরীক্ষায় বলার মতো বৈশিষ্ট্য: subject-oriented, integrated, time-variant, non-volatile।
স্কিমা: star schema (fact table + denormalized dimensions), snowflake (dimensions normalized)। ক্ষুদ্র star উদাহরণ: Fact_Sales(order_id, date_id, product_id, store_id, qty, revenue) + Date(date_id, day, month, year) + Product(product_id, name, category) + Store(store_id, city, region)।
ETL বিস্তারিত: Extract (OLTP/CSV/লগ থেকে ডাটা নেয়া), Transform (clean, conform, aggregate), Load (initial bulk অথবা incremental)। Slowly changing dimensions (Type 1/2/3) উল্লেখ করলে বাড়তি পয়েন্ট।
কেন দরকার: ডাটা একত্র করে, ঐতিহাসিক বিশ্লেষণ সম্ভব করে, বিশ্লেষণাত্মক কুয়েরি দ্রুত করে, OLAP কিউব সাপোর্ট করে।
পরীক্ষা প্রশ্ন (৬ মার্ক): Data warehouse সংজ্ঞা বলো এবং sales-এর জন্য star schema আঁকো।
মডেল উত্তর: সংজ্ঞা + fact ও dimension টেবিলের নাম/ফিল্ডসহ স্কিমা।

## 5. Characterization and Discrimination — Methods + Examples + Exam Qs

Characterization: summarization/generalization of target class — attribute-oriented induction (generalize low-level values to higher-level concept), data cube based aggregation. Output: typical profile (e.g., High-value customer: age 30–45, freq>4, avg spend>₹5000).
Discrimination (contrast set mining): find rules/attributes that distinguish target class from contrast class. Techniques: contrast sets, emerging patterns, decision tree rule extraction. Example: churners vs non-churners: churners have <2 purchases in last 6 months AND >3 complaints.
When to use which: characterization for summarizing a group; discrimination when you need differentiating rules for decision making.
Exam Q (5 marks): Define both and give one algorithm/example for each.
Model Answer: definition + attribute-oriented induction (characterization) & contrast-set mining (discrimination) with examples.

## ৫. Characterization ও Discrimination — পদ্ধতি + উদাহরণ + পরীক্ষা প্রশ্ন

Characterization: লক্ষ্য শ্রেণির সারসংক্ষেপ/সারমর্ম — attribute-oriented induction (কম-লেভেলের মানকে উচ্চ-লেভেলে জেনেরালাইজ করা), data cube aggregation। আউটপুট: টাইপিক্যাল প্রোফাইল (যেমন High-value customer: বয়স ৩০–৪৫, freq>4, avg spend>₹5000)।
Discrimination (contrast set mining): লক্ষ্য ও কনট্রাস্ট শ্রেণীর মধ্যে পার্থক্য বের করে রুল/অ্যাট্রিবিউট চিহ্নিত করা। পদ্ধতি: contrast sets, emerging patterns, decision tree থেকে রুল এক্সট্রাকশন। উদাহরণ: churners বনাম non-churners: churners—গত ৬ মাসে কেনাকাটা <2 এবং complaint_count>3।
কখন কোনটা ব্যবহার: characterization গ্রুপ সারসংক্ষেপে; discrimination যখন পার্থক্য বের করে সিদ্ধান্ত নিতে হবে।
পরীক্ষা প্রশ্ন (৫ মার্ক): উভয়ের সংজ্ঞা বলো ও প্রতিটির একটি পদ্ধতি ও উদাহরণ দাও।
মডেল উত্তর: সংজ্ঞা + attribute-oriented induction (characterization) ও contrast-set mining (discrimination) + উদাহরণ।

## 6. Associations and Correlations — Full math, examples, interpretation

Association Rules (Transactions):

- Support(A∪B) = count(A and B)/N.
- Confidence(A→B) = support(A∪B)/support(A) = P(B)

- Lift(A→B) = confidence(A→B)/support(B) = P(B)

| **Association Rules**                   | **Correlation**                                  |
| --------------------------------------- | ------------------------------------------------ |
| Works on transactional datasets.        | Works on numeric datasets.                       |
| Measures co-occurrence.                 | Measures linear relationship.                    |
| Uses Support, Confidence, Lift.         | Uses Pearson correlation coefficient.            |
| Example: Bread → Butter.                | Example: Height increases with weight.           |
| বাংলায়: পণ্যগুলো একসাথে কীভাবে কেনা হয়। | বাংলায়: দুই ভেরিয়েবল একসাথে কীভাবে পরিবর্তিত হয়। |

## 7. Are All Patterns Interesting? — Measures & statistical tests

Short answer: No. Many discovered patterns are trivial, redundant, or spurious. Need interestingness evaluation.
Objective Measures: support, confidence, lift, chi-square (test independence), information gain, conviction.
Chi-square (brief math): build contingency table for presence/absence of A and B, compute expected counts under independence: E = (row_total \* col_total)/N. χ² = Σ (O−E)²/E. Compare to χ² critical value (df=1 usually) or compute p-value. Large χ² → reject independence.
Subjective Measures: novelty, usefulness, actionability, surprisingness, simplicity.
Example of uninteresting rule: If item X is in nearly all transactions (very high support), rules X→Y may be trivially true; or rule involving attributes that are derived/duplicate.
Exam Q (5 marks): Why not all patterns are interesting? Provide 2 objective and 2 subjective measures and explain chi-square briefly.
Model Answer: short paragraph + measures + χ² explanation.

## ৭. সব Pattern কি Interesting? — মাপকাঠি ও স্ট্যাটিস্টিকাল টেস্ট

সংক্ষেপে: না। অনেক প্যাটার্ন তুচ্ছ, পুনরাবৃত্তি বা স্পারিওস হতে পারে; তাই interestingness মূল্যায়ন জরুরি।
Objective মাপ: support, confidence, lift, chi-square (ইনডিপেনডেন্স টেস্ট), information gain, conviction।
Chi-square (সংক্ষেপ গণিত): A ও B এর উপস্থিতি/অনুপস্থিতি নিয়ে contingency table তৈরি করো; independence ধরে expected count E = (row_total \* col_total)/N; χ² = Σ (O−E)²/E; বড় χ² মানে independence ঝেড়ে ফেলা যায়।
Subjective মাপ: novelty (নতুনত্ব), usefulness (উপযোগিতা), actionability (ব্যবহারে আসবে কি না), surprisingness, simplicity।
অপ্রয়োজনীয় রুল উদাহরণ: কোনো আইটেম X সব ট্রানজ্যাকশনে থাকলে X→Y রুল তুলনামূলকভাবে তুচ্ছ।
পরীক্ষা প্রশ্ন (৫ মার্ক): কেন সব প্যাটার্নই interesting নয়? ২টি objective ও ২টি subjective measure বলো; chi-square সংক্ষেপে ব্যাখ্যা করো।
মডেল উত্তর: সংক্ষিপ্ত অনুচ্ছেদ + মাপকাঠি + χ² সূত্র।

## 8. Semi-Supervised Learning & Active Learning — Practical algorithms + exam Qs

Semi-Supervised Learning (SSL): uses both labeled & unlabeled data to improve learning. Key methods: self-training (label confident unlabeled iteratively), co-training (two independent feature-views teach each other), transductive SVM, graph-based label propagation. Use-cases: when labeling expensive (medical), huge unlabeled logs available.
Active Learning: model queries oracle (human annotator) for labels of most informative instances. Strategies: uncertainty sampling (lowest classifier confidence), query-by-committee (highest disagreement), expected error reduction. Use-case: annotate images for deep learning with minimal labels.
Pros/Cons quick: SSL reduces labeling need automatically but may propagate errors; Active learning chooses labels wisely but requires human oracle.
Exam Q (5 marks): Compare SSL & Active Learning; name one algorithm/strategy each and give a use-case.
Model Answer: define both, self-training & uncertainty sampling, use-cases (medical images / expensive labeling).

## ৮. Semi-Supervised ও Active Learning — ব্যবহারিক অ্যালগরিদম + পরীক্ষা Qs

Semi-Supervised Learning (SSL): লেবেলড ও আনলেবেলড ডাটা দুইটাই ব্যবহার করে মডেল উন্নত করে। প্রধান পদ্ধতি: self-training (confident আনলেবেলড স্যাম্পলগুলোতে নিজে লেবেল দেয়া), co-training (বিভিন্ন ফিচার-ভিউ একে অপরকে শেখায়), transductive SVM, গ্রাফ-ভিত্তিক লেবেল প্রোপাগেশন। ব্যবহার: লেবেল খরচ বেশি এমন জায়গা (মেডিক্যাল ইমেজ)।
Active Learning: মডেল সবচেয়ে তথ্যবহুল উদাহরণগুলোকে মানুষকে লেবেল করায় (oracle)। কৌশল: uncertainty sampling (কম কনফিডেন্স), query-by-committee (মডেলগুলোর মতভেদ), expected error reduction। ব্যবহার: ছবির অ্যানোটেশন যেখানে মানুষের লেবেল ব্যয়বহুল।
সুবিধা/অসুবিধা: SSL লেবেলিং কমায় কিন্তু ভুল লেবেল প্রোপাগেট করতে পারে; Active Learning লেবেল কমায় কিন্তু মানুষের উপস্থিতি প্রয়োজন।
পরীক্ষা প্রশ্ন (৫ মার্ক): SSL ও Active Learning তুলনা করো; প্রতিটির একটি অ্যালগরিদম বলো ও ব্যবহার উদাহরণ দাও।
মডেল উত্তর: SSL→self-training (medical images), Active→uncertainty sampling (image annotation)।

## 9. Major Issues in Data Mining — Full list, explanations & mitigations

1. Scalability: Big data needs scalable algorithms. Mitigation: sampling, parallel/ distributed computing (MapReduce, Spark), online/incremental algorithms.
2. High dimensionality (curse): distance loses meaning; mitigation: feature selection (filter/wrapper/embedded), dimensionality reduction (PCA, LDA, autoencoders).
3. Data Quality: missing, noisy, inconsistent data; mitigation: robust cleaning, validation, outlier handling.
4. Privacy & Security: sensitive info; mitigation: anonymization (k-anonymity, l-diversity), differential privacy, secure multi-party computation.
5. Heterogeneous data & integration: format/schema mismatch; mitigation: schema mapping, ontology alignment, data fusion.
6. Dynamic/Streaming data & concept drift: models become stale; mitigation: online learning, adaptive windows, drift detection.
7. Imbalanced data: minority class rare; mitigation: resampling (oversample, SMOTE), cost-sensitive learning, appropriate metrics (precision/recall, ROC).
8. Interpretability: complex models (deep nets) hard to explain; mitigation: use explainable models (decision trees, LIME/SHAP for explanations).
   Exam Q (8 marks): Describe any four major issues and propose mitigations.
   Model Answer: pick four, ২–৩ লাইন সমস্যা + ১–২ mitigation per issue.

## ৯. ডাটা মাইনিং-এর প্রধান সমস্যা — সম্পূর্ণ তালিকা, বিশ্লেষণ ও প্রতিকার

১. Scalability: বিশাল ডাটা → সমাধান: sampling, parallel/distributed computing (MapReduce, Spark), incremental algorithms।
২. High dimensionality (curse): ডাইমেনশন বাড়লে distance ও generalization সমস্যা; সমাধান: ফিচার সিলেকশন (filter/wrapper/embedded), dimensionality reduction (PCA, LDA, autoencoders)।
৩. Data Quality: মিসিং, noisy, inconsistent ডাটা → সমাধান: ডাটা ক্লিনিং, ভ্যালিডেশন, আউটলার হ্যান্ডলিং।
৪. Privacy & Security: সংবেদনশীল তথ্য → সমাধান: anonymization (k-anonymity, l-diversity), differential privacy, secure computation।
৫. Heterogeneous data & integration: বিভিন্ন ফরম্যাট/স্কিমা → সমাধান: schema mapping, ontology alignment, data fusion।
৬. Dynamic/Streaming data & concept drift: মডেল পুরাতন হয়ে যায় → সমাধান: online learning, adaptive windows, drift detection।
৭. Imbalanced data: minority class কম → সমাধান: resampling (SMOTE), cost-sensitive learning, precision/recall ব্যবহার।
৮. Interpretability: জটিল মডেল বোঝা কঠিন → সমাধান: explainable models (decision trees), LIME/SHAP ব্যাখ্যা পদ্ধতি।
পরীক্ষা প্রশ্ন (৮ মার্ক): ডাটা মাইনিং-এর যেকোন ৪টি সমস্যা ও প্রতিরোধ বলো।
মডেল উত্তর: ৪টি বেছে নিয়ে ২–৩ লাইন সমস্যা + ১–২ লাইন mitigation।

## Quick Exam-Ready Question Bank (covering all above topics) — with brief model answers

Short Qs (2–4 marks):

- Define data mining. (1–2 lines)
- What is OLAP? Name two OLAP operations. (roll-up, drill-down)
- List KDD 7 steps in order.
- Define support and confidence.
- What is difference between association and correlation?
  Long Qs (8–10 marks):
- Explain KDD steps 7-point with an e-commerce pipeline and one technique per step.
- Compare OLAP and OLTP and show star schema for sales.
- Given transactions (10 rows) compute support/confidence/lift and interpret.
  Problem Q (math/computation):
- Given contingency table, compute chi-square and conclude independence at α=0.05.
  Model Answers: Provide concise bullet answers or stepwise computations—(I'll generate specific mock problems + full solutions on request).

## দ্রুত পরীক্ষার প্রশ্ন ব্যাংক (উপরের সব টপিক কভার করে) — সংক্ষিপ্ত মডেল উত্তরসহ

সংক্ষিপ্ত প্রশ্ন (২–৪ মার্ক):

- Data mining সংজ্ঞা বলো। (১–২ লাইন)
- OLAP কী? দুটি OLAP অপারেশন বলো। (roll-up, drill-down)
- KDD ৭ ধাপ ক্রমানুসারে বলো।
- Support ও confidence কী? সংজ্ঞা বলো।
- Association ও correlation পার্থক্য বলো।
  দীর্ঘ প্রশ্ন (৮–১০ মার্ক):
- KDD ৭ ধাপ ব্যাখ্যা করো ও e-commerce pipeline এ প্রতিটি ধাপের উদাহরণ দাও।
- OLAP ও OLTP তুলনা করো এবং sales-এর star schema দেখাও।
- দেওয়া ১০টি ট্রানজ্যাকশন থেকে support/confidence/lift গণনা করো ও ব্যাখ্যা করো।
  গণিত/প্রব্লেম প্রশ্ন:
- প্রদত্ত contingency table থেকে chi-square গণনা করে α=0.05 এ independence সিদ্ধান্ত নাও।
  মডেল উত্তর: সংক্ষিপ্ত বুলেট বা ধাপে ধাপে গণনা—(তুমি চাইলে আমি নির্দিষ্ট উদাহরণ + পূর্ণ গণনা তৈরি করে দেব)।
