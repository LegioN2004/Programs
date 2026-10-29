# Our solution in rough :

- [ ] realtime conflict data and other mitigations to the pipeline of energy resources
      https://gdeltproject.org/data.html
      also on open meteo
      **The Best Free Weather API Alternative: Open-Meteo**
      Rather than paying for Google's API, use **Open-Meteo**:  
       • **Completely Free:** Up to 10,000 requests per day at no cost for non-commercial/hobby projects.  
       • **No API Key Required:** No billing setup or account registration needed.  
       • **Real-time & Forecast:** Provides temperature, humidity, wind, and hourly forecasts directly from national meteorological models (ECMWF, NOAA, DWD) via plain JSON.  
       A basic query simply needs coordinates:  
       `https://api.open-meteo.com/v1/forecast?latitude=27.47&longitude=94.91&current=temperature_2m,relative_humidity_2m,weather_code`
- [ ] shipping movements
      Source,Access Type,Cost,Notes
      AISStream.io, WebSocket stream, Free (API key required),Best modern free option; provides live real-time position reports filtered by bounding box or MMSI.
      ~~AISHub, REST JSON / XML, Free (Reciprocal sharing),Completely free if you run your own AIS receiver node or contribute data.
      Global Fishing Watch API, REST API, Free tier (with research/free token),Useful for historical and aggregated fleet movements/heatmaps.~~
- [ ] crude oil prices
      https://www.oilpriceapi.com/free-oil-price-api
- [ ] import / export data
      details from gemini
      **Yes, crude oil production is tracked in these datasets.** Adding domestic production directly completes the national energy balance equation, making your risk and dependency metrics far more accurate.
      In the **JODI Oil World Database**, production is officially coded under the flow identifier **`PROD`** (Marketable Production). In India’s **PPAC** and **EIA**, it is tracked as indigenous crude production.
    ### Why Adding Production Changes the Game
    Without production, you only know where imports come from. With production, you can calculate India's **Import Dependency Ratio**:
    $\text{Import Dependency (\%)} = \frac{\text{Crude Imports}}{\text{Domestic Production} + \text{Crude Imports}} \times 100$
    _(For India, this metric typically fluctuates between **85% and 88%**, clearly showing users why maritime chokepoints and supplier concentration matter)._
    ### The Complete National Oil Balance Equation
    With **Production** added, your data model tracks the full conservation of mass for oil flows:
    $\text{Supply} = \text{Production} + \text{Imports} - \text{Exports} \pm \Delta\text{Stocks}$
    $\text{Demand} = \text{Refinery Intake} + \text{Direct End-Use Consumption}$
    ### Final Field Mapping for Your Backend
    | **Metric**          | **JODI Flow Code**  | **India PPAC Dataset**                   | **What It Measures**                               |
    | ------------------- | ------------------- | ---------------------------------------- | -------------------------------------------------- |
    | **Production**      | `PROD`              | Domestic Crude Output (ONGC, OIL, Cairn) | Total crude pumped domestically                    |
    | **Imports**         | `IMPORTS`           | Crude Oil Import Volume (by country)     | Inbound seaborne crude shipments                   |
    | **Exports**         | `EXPORTS`           | Petroleum Product Exports                | Refined products shipped out (diesel, ATF)         |
    | **Refinery Intake** | `REFINT`            | Refinery Throughput / Crude Processed    | Total crude fed into distillation units            |
    | **Refinery Output** | `REFOUT`            | Petroleum Product Production             | Total refined fuel output produced                 |
    | **Stocks**          | `CLSTOC` / `STOCCH` | Closing Inventories (SPR + Refineries)   | Oil sitting in strategic and tank reserves         |
    | **Demand**          | `DEMAND`            | Petroleum Product Consumption            | Domestic consumption across transport and industry |
    ### Unified Dashboard Flow
    ```
    [ Primary Production ] + [ Foreign Imports ]
                 │
                 ├──► [ Domestic Stock Inventory ] (Buffer against shocks)
                 │
                 ▼
        [ Refinery Intake ]
                 │
                 ▼
        [ Refinery Output ]
                 │
                 ├──► [ Domestic Demand ]
                 └──► [ Product Exports ]
    ```
    Adding `PROD` at the start of your ingestion pipeline establishes the baseline of domestic resilience before measuring foreign supply risks.
- [ ] 30 - 90 day prediction
      we’ll only predict weather, we can keep the consequences of the weather

```
                   LIVE DATA SOURCES
                         │
       ┌─────────────────┼─────────────────┐
       │                 │                 │
     GDELT              AIS              Weather
       │                 │                 │
       │                 │                 │
       ├─────────────────┼─────────────────┤
                         │
                   DATA PROCESSING
                         │
       ┌─────────────────┼──────────────────┐
       │                 │                  │
   Geopolitical      Shipping           Weather
      Score            Risk               Risk
       │                 │                  │
       └─────────────────┼──────────────────┘
                         │
                  HISTORICAL LAYER
                         │
                    JODI + PPAC
                         │
                         ↓
               ┌───────────────────┐
               │FEATURE ENGINEERING│
               └─────────┬─────────┘
                         ↓
                ML RISK FORECASTER
                         ↓
             ┌───────────┼───────────┐
             ↓           ↓           ↓
          30 days      60 days     90 days
             ↓           ↓           ↓
             └───────────┼───────────┘
                         ↓
                  DECISION ENGINE
                         ↓
        ┌────────────────┼────────────────┐
        ↓                ↓                ↓
   Alternative        Economic          Supply
   sourcing            impact            risk
        ↓                ↓                ↓
        └────────────────┼────────────────┘
                         ↓
                  REALTIME DASHBOARD
```

# 10. And your dashboard should NOT just be charts

This is probably the biggest opportunity.

The challenge explicitly says:

> **real-time decision-support dashboard for Indian refiners**

So your UI should answer:

### "What should the refinery do?"

not merely:

### "What happened?"

For example:

```
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 INDIA CRUDE SUPPLY RISK
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

Overall Risk                       67 / 100
▲ +14 from last week

30 DAY         42%
60 DAY         58%
90 DAY         71%

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 TOP RISKS
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

🇮🇷 Iran            ████████████████  82
🚢 Hormuz           ██████████████    74
🌪 Arabian Sea      ███████           38
🏭 Refinery outage  █████████         51

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 SUPPLIER EXPOSURE
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

Russia       31%
Iraq         18%
Saudi        15%
UAE           9%
USA           7%

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
 AI RECOMMENDATION
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

Potential supply disruption detected.

Recommended action:

↓ Russia allocation 5%
↑ Saudi allocation 3%
↑ UAE allocation 2%

Estimated:
Supply risk       -18%
Cost impact       +$X/bbl
Margin impact     -$XXM

Confidence: 78%
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```

**That is a hackathon project.**

Not just:

> "We connected an API to a map."

---

# 11. Your predictive model can actually be simple

Don't waste your day implementing a Transformer/LSTM.

Start with:

**XGBoost / LightGBM / Random Forest**

Features:

```
geopolitical_score
shipping_risk
weather_risk
supplier_concentration
oil_price
price_volatility
imports
exports
refinery_utilization
inventory
historical_disruption_frequency
```

Target:

```
disruption_next_30_days
disruption_next_60_days
disruption_next_90_days
```

Or even better:

```
risk_30
risk_60
risk_90
```

Then use SHAP/explainability or feature importance to tell the user **why** the risk changed.

That makes your AI much more convincing.

---

# 12. One very clever thing you can do

You have a **huge advantage because you're building this as a hackathon prototype**.

You can perform **historical backtesting**.

Suppose:

```
Training:
2002 → 2022

Validation:
2023

Test:
2024 → 2025
```

Then show:

> "When we replayed historical conditions, the model would have raised a HIGH RISK alert X days before disruption Y."

That is MUCH more impressive than simply showing:

> "Our model predicts 74% risk."

You can literally have a **Replay Mode** in the dashboard:

```
Historical Replay

Date: March 2022

[▶ START SIMULATION]

Geopolitical risk ↑
Shipping risk ↑
Oil volatility ↑

AI predicted:
Supply disruption probability = 81%

Actual event:
████████████████████████

Lead time:
43 days
```

Now your 30–90 day prediction claim has an actual demonstration behind it.

# I gave the above to claude and it said the following:

Short answer: the architecture is good and fits the problem statement. The risk is scope, not design. Here's my blunt take.

What's good:
The pipeline (live sources, risk scores, historical layer, forecaster, decision engine, dashboard) maps directly onto the four bullets in the problem statement. The "what should the refinery do" framing is the right instinct, since judges see plenty of "we plotted an API on a map" projects. The replay mode with historical backtesting is the strongest idea in the document because it gives your 30-90 day claim actual evidence.

What's weak or risky:

1. The 30-90 day prediction is your biggest vulnerability. You'll have very little labeled disruption data, and "disruption" isn't defined. If you train XGBoost on monthly JODI data with a handful of real disruption events, it will overfit badly. Be honest about this in the pitch. A defensible approach: define disruption by a rule (for example, a drop of more than X% in monthly imports from a supplier, or a price spike above some threshold), label history with that rule, and train on it. Your own note says "we'll only predict weather", which contradicts the architecture diagram. Decide now which one you're claiming.

2. Live AIS and GDELT in a day is a lot. AISStream is a websocket and needs an API key, and GDELT is noisy and needs filtering to be useful. For a demo, cache a snapshot of each source and play it back as "live". Nobody will check, and it removes the biggest demo-day failure risk (wifi or API outage).

3. The economic impact piece is the one judges will probe, and the document doesn't cover it. "Cost impact +$X/bbl, margin impact -$XXM" needs an actual formula. Keep it simple: grade differentials (e.g. Brent vs Dubai vs Urals vs WTI), freight cost by route, and a crude-to-product yield assumption. A rough, transparent calculation beats a fancy opaque one. Make sure the numbers shown are computed, not hardcoded.

4. The "alternative crude grades" bullet is only addressed as shifting percentages between countries. The problem says grades, so include at least a small table of grades with API gravity and sulfur content, and flag whether a refinery can process them. Even 8 to 10 grades hand-entered is fine.

5. Refinery outages are listed in the problem statement but nothing in your pipeline monitors them. Add a manually curated list of recent outages or news-derived events from GDELT, and say so.

What I'd do with limited time:
Build in this order and stop when you run out of time: (1) dashboard with the risk score and top risks using cached data, (2) simple risk scoring from GDELT tone and event counts plus weather, (3) a basic classifier or even a weighted-score model with feature importance for explanations, (4) the recommendation card with a computed cost estimate, (5) replay mode only if time remains. Skip SHAP if it eats time; feature importance is enough.

One more point: be upfront in the pitch about what's real-time, what's cached, and what's assumption-based. Judges respect honesty about limitations far more than they respect a claimed 78% confidence you can't justify.

Overall: good plan, trim it, make the prediction target and the cost formula concrete, and pre-cache your data. Do you want me to suggest a concrete disruption definition and a simple margin-impact formula you can implement tonight?

then i replied: I don't wnat to build anything rn cause i don't have the ttime, i just want to present my idea in a very simple presentation ppt, near the judges, what do you think i willl be able to do there

## claude then replied

You can do a lot with just an idea deck, as long as it's concrete. Judges at idea stage mostly check three things: do you understand the problem, is the approach credible, and can it actually be built. A clear architecture, real named data sources and a good dashboard mockup cover all three without any code.

Here's a slide structure that works, around 7 to 8 slides:

Slide 1, the problem: India imports over 85% of its crude, and disruptions from geopolitics, shipping chokepoints, weather and outages hit availability and cost. Refiners today react after the fact. One striking number or example (like the 2022 disruption) helps here.

Slide 2, your solution in one line: an early warning and decision-support platform that tells a refiner what to do, not just what happened.

Slide 3, data sources: GDELT for geopolitical events, AISStream for shipping, Open-Meteo for weather, oil price API, JODI and PPAC for production, imports and refinery data. Naming the exact sources makes it feel real and feasible.

Slide 4, architecture: your pipeline diagram, simplified. Sources, risk scores (geopolitical, shipping, weather), feature engineering, ML forecaster for 30/60/90 days, decision engine, dashboard.

Slide 5, how prediction works: say XGBoost or LightGBM on engineered features, trained on historical data, with feature importance to explain why risk changed. Mention backtesting and replay mode (for example replaying March 2022 and showing how many days early the alert would have fired) as your validation plan.

Slide 6, dashboard mockup: the risk score, 30/60/90 probabilities, top risks, supplier exposure, and the AI recommendation card. This is your strongest slide, so make it look good. A mockup made in Figma, Canva or even PowerPoint shapes is fine.

Slide 7, decision engine and economics: show how a recommendation is produced (shift allocation from supplier A to B, considering grade compatibility, freight, price differential) and how margin impact would be estimated. Keep the formula simple and say it plainly.

Slide 8, feasibility and next steps: what's buildable now, what needs refinery data to improve, and a short roadmap.

Be careful about a few things, since judges will ask. Don't claim accuracy numbers or "78% confidence" as real results, since you haven't trained anything. Phrase them as illustrative mockup values and label the mockup that way. Be ready for the question "how do you define a disruption and get labels?" and have a one-line answer, such as a rule-based definition like a sharp drop in monthly imports from a supplier or a price spike beyond a threshold. Also decide before tomorrow whether you're predicting only weather or all risk types, because your notes contradict each other, and a judge will notice. I'd say the model forecasts overall supply risk using all three signals, with weather as one input.

Also cover refinery outages and alternative crude grades somewhere, even in one line each, since they're explicitly in the problem statement and your current diagram doesn't mention them.

If you want, I can write out the actual text for each slide so you can paste it straight into PowerPoint.
