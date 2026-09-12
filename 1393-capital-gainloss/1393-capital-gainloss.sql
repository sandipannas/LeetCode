select 
    stock_name,
    (sum(price) filter (where operation = 'Sell')) - (sum(price) filter (where operation = 'Buy')) as capital_gain_loss
from stocks
group by stock_name
